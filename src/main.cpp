/*
This program attemps to find a solution to the travelling salesman's problem by using heuristic methods that could be classified
as belonging to the frame of genetic algothims.

Author : Maxens ACHIEPI-AUTRET
Date : 16.12.2016
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <time.h>
#include "Point.h"
#include "Path.h"

using namespace std;

int main(int argc, char *argv[])
{
    if(argc!=4){
        cout << "Wrong number of arguments" << endl;
        return -1;
    }
    // INITIALIZATION
    srand(time(NULL));
    
    stringstream nbCitSS(argv[1]), initPopSS(argv[2]), nbGenSS(argv[3]);

    int nbCit, initPop, nbGen;
    
    nbCitSS >> nbCit;
    initPopSS >> initPop;
    nbGenSS >> nbGen;

    cout << "Welcome to the Travelling Salesman's Problem Simulator" << endl << endl;
    /*cout << "Please select the number of cities : ";

    cin >> nbCit; // sadly we don't check if it is truly a positive integer

    cout << endl;

    cout << "Please select the initial population number (> 20) : ";

    cin >> initPop; // very sadly we don't check if it is truly a positive integer

    cout << endl;

    cout << "Please select the number of generations : "; // the number of offsprings we will create (two offsprings per gen)

    cin >> nbGen; // very very sadly we don't check if it is truly a positive integer*/
    
    Path* pathArray = new Path[initPop]; // allocating the space for the array of paths.
    
    cout << "The number of cities is : " << nbCit << endl;
    cout << "The initial population number is : " << initPop << endl;
    cout << "The number of generation is : " << nbGen << endl;

    pathArray[0].setSize(nbCit); // the path's size will be as asked by the user
    pathArray[0].fillPath(); // here we fill the first path with random cities
	
	int bestGenArray[nbGen];
	int moyGenArray[nbGen];
	
    int bestGen0 = pathArray[0].length(); // we will compute the best path of generation 0 so that we can compare it to the best path at the final generation
    int moyGen0 = bestGen0;
    int temp = -1;

    for(int i = 1; i < initPop; i++)
    {
        pathArray[i] = pathArray[i-1];
        pathArray[i].shuffle(); // here we fill the other paths with variations of the first path

        temp = pathArray[i].length();

        moyGen0 += temp;

        bestGen0 = temp < bestGen0 ? temp : bestGen0;

    }

    moyGen0 /= initPop;

    // SELECTION
    /* In this program, we will use Tournament Selection, because it is easy to implement and requires little computations
       For reference, please see the Wikipedia page about Tournament Selection */

    int numOfPath = 10; // this allows us to adjust selection pressure

    Path* selectPath1 = new Path[numOfPath]; /* In these arrays we will select 10 path randomly and then compare them to select
                                             the two best ones. They will be used as parents for the offspring. */
    Path* selectPath2 = new Path[numOfPath];

    int* tabDist1 = new int[numOfPath]; // in these arrays we will calculate the fitness of each path in our selection.
    int* tabDist2 = new int[numOfPath];

    int indexCut = -1;
    int slct1, slct2, c1, c2; //slcti is number of already selected paths; ci is counter

    int prob1 = -1;
    int prob2 = -1;
    int a1,a2; //ai is probability threshold;

    int indexBest1, indexBest2;
    int indexCross1, indexCross2; // indexes of the cutting during crossover

    int probMut;
    int treshMut = 1; // % chance of mutation

    int indexReinject1;
    int indexReinject2;

    bool replace1, replace2;
    int nbTry1,nbTry2;

    Path offSpring1(nbCit);
    Path offSpring2(nbCit);

    int cpt1, cpt2;

    int i2,i3;
    
    string file_name_best = ((string)"../BestFit_")+argv[1]+"_"+argv[2]+"_"+argv[3]+".txt";
    string file_name_avg = ((string)"../AvgFit_")+argv[1]+"_"+argv[2]+"_"+argv[3]+".txt";
    
    ofstream file_best(file_name_best.c_str());
    ofstream file_avg (file_name_avg.c_str());
    
    if(!file_best.is_open() || !file_avg.is_open())
    {
        cout << "Can't open file" << endl;
        return -1;
    }

    for(int j = 0; j < nbGen; j++) // Loop on all generations
    {

        if(!(j%100))
        {
            cout << "Generation " << j << endl;
        }
        
        bestGenArray[j] = pathArray[0].length();
        
        for(int cpt_fit = 1; cpt_fit < initPop; cpt_fit++)
        {
            temp = pathArray[cpt_fit].length();

            moyGenArray[j] += temp;

            bestGenArray[j] = temp < bestGenArray[j] ? temp : bestGenArray[j];
        }
        
        moyGenArray[j] /= initPop;
        
        file_best << bestGenArray[j] << endl;
        file_avg << moyGenArray[j] << endl;
        
        // Random selection of 10 paths, twice. We have to make sure we don't select the same path twice.

        indexCut = (numOfPath-1) + rand()%((initPop-11) - (numOfPath-1) +1 ); //between 9 and initPop-11

        Path* pathList1 = copyPathArray(pathArray,0,indexCut);

        Path* pathList2 = copyPathArray(pathArray,indexCut+1,initPop-1);


        slct1 = 0;
        slct2 = 0;

        c1 = 0;
        c2 = 0;

        for(int k = 0; k < indexCut+1 && c1 != numOfPath; k++)
        {
             /* the method to randomly select the paths is inspired by a stackexchange post */
            prob1 = 1 + rand()%(indexCut+1 - k); // between 1 and indexCut+1 - k

            a1 = numOfPath - slct1;

            if(prob1 <= a1)
            {
                slct1++;
                selectPath1[c1] = pathList1[k];
                tabDist1[c1] = pathList1[k].length();
                c1++;
            }

        }

        for(int l = 0; l < initPop-indexCut-1 && c2 != numOfPath; l++)
        {

            prob2 = 1 + rand()%(initPop-indexCut-1 - l); //between 1 and initPop-indexCut-1 - l

            a2 = numOfPath - slct2;

            if(prob2 <= a2)
            {
                slct2++;
                selectPath2[c2] = pathList2[l];
                tabDist2[c2] = pathList2[l].length();
                c2++;
            }
        }

        indexBest1 = indexOfMinVal(tabDist1,numOfPath);
        indexBest2 = indexOfMinVal(tabDist2,numOfPath);

        // CROSSOVER & MUTATION

        /*
        In this implementation we will use Order 1 Crossover and Single Swap
        For reference please see :
        http://www.rubicite.com/Tutorials/GeneticAlgorithms/CrossoverOperators/Order1CrossoverOperator.aspx
        http://www.rubicite.com/Tutorials/GeneticAlgorithms/MutationOperators/SingleSwapMutationOperator.aspx
        */

        indexCross1 = 1 + rand()%(nbCit-2); // between 1 and nbCit-2
        indexCross2 = indexCross1 + rand()%(nbCit-2 - indexCross1 + 1); // between indexCross and nbCit-2

        Path p1(indexCross2 - indexCross1 + 1);
        Path p2(indexCross2 - indexCross1 + 1);

        offSpring1[0] = pathArray[0].getPointFromArray(0);
        offSpring2[0] = pathArray[0].getPointFromArray(0);

        for(int i1 = indexCross1; i1 <= indexCross2; i1++)
        {
            offSpring1[i1] = selectPath1[indexBest1].getPointFromArray(i1);
            p1[i1 - indexCross1] = offSpring1[i1];

            offSpring2[i1] = selectPath2[indexBest2].getPointFromArray(i1);
            p2[i1 - indexCross1] = offSpring2[i1];
        }

        cpt1 = 0;

        i2 = 0;

        Point pt1;

        while(i2 < nbCit)
        {
            pt1 = selectPath2[indexBest2].getPointFromArray(i2);

            if(!(p1.pointInPath(pt1)))
            {
                if(cpt1 < indexCross1 || cpt1 > indexCross2)
                {
                    offSpring1[cpt1] = selectPath2[indexBest2].getPointFromArray(i2);

                    i2++;
                }

                cpt1++;
            } else
            {
                i2++;
            }
        }

        cpt2 = 0;

        i3 = 0;

        Point pt2;

        while(i3 < nbCit)
        {
            pt2 = selectPath1[indexBest1].getPointFromArray(i3);

            if(!(p2.pointInPath(pt2)))
            {
                if(cpt2 < indexCross1 || cpt2 > indexCross2)
                {
                    offSpring2[cpt2] = selectPath1[indexBest1].getPointFromArray(i3);

                    i3++;
                }

                cpt2++;
            } else
            {
                i3++;
            }
        }

        probMut = 1+ rand()%100; // between 1 and 100

        if(probMut <= treshMut) // mutation with low probability
        {
            offSpring1.ranSwap();
            offSpring2.ranSwap();
            cout << "MUTATION" << endl;
        }

        replace1 = false;
        replace2 = false;
        nbTry1 = 0;
        nbTry2 = 0;

        while(!replace1 && nbTry1 < 20) // we limit the number of tries because it's possible to get an offspring with the worst length of the population
        {
            indexReinject1 = rand()%(indexCut+1);
            nbTry1++;

            if(offSpring1.length() < pathList1[indexReinject1].length())
            {
                pathArray[indexReinject1] = offSpring1;
                replace1 = true;
            }
        }

        while(!replace2 && nbTry2 < 20)
        {
            indexReinject2 = rand()%(initPop-indexCut-1);
            nbTry2++;

            if(offSpring2.length() < pathList2[indexReinject2].length())
            {
                pathArray[indexReinject2 + indexCut + 1] = offSpring2;
                replace2 = true;
            }
        }

        delete[] pathList1;
        delete[] pathList2;

    }
    
    file_best.close();
    file_avg.close();

    int moyGenEnd = 0;
    int bestGenEnd = pathArray[0].length();
    int tempEnd = -1;

    for(int i4 = 0; i4 < initPop; i4++)
    {
        tempEnd = pathArray[i4].length();

        bestGenEnd = tempEnd < bestGenEnd ? tempEnd : bestGenEnd;

        moyGenEnd += tempEnd;
    }

    moyGenEnd /= initPop;

    cout << endl;
    cout << "The best path of generation 0 had a length of : " << bestGen0 << endl;
    cout << "The generation 0 had a mean length of : " << moyGen0 << endl;
    cout << endl;

    cout << "The best path of generation " << nbGen << " has a length of : " << bestGenEnd << endl;
    cout << "The generation " << nbGen << " had a mean length of : " << moyGenEnd << endl;
    
    string pytCmd = "python ../src/tryPyth.py " + file_name_avg + " " + file_name_best;
    
    system(pytCmd.c_str());
    // END OF SIMULATION
    delete[] pathArray;
    delete[] selectPath1;
    delete[] selectPath2;
    delete[] tabDist1;
    delete[] tabDist2;
//    delete[] &offSpring1;
//		cout << "ah";
//    delete[] &offSpring2;
//		cout << "ah";

    return 0;

}

#include <iostream>
#include "Candidate.cpp"
#include <queue>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

Candidate generateCandidate(string name, 
						string surname, 
						int cppDevelopmentScore, 
						int OSScore, 
						int experienceScore, 
						int agileScore, 
						int gradeScore,
						int educationStatus){
							
	Candidate candidate(name, surname);
	
	candidate.setCPPDevelopmentScore(cppDevelopmentScore);
	candidate.setOSScore(OSScore);
	candidate.setExperienceScore(experienceScore);
	candidate.setAgileScore(agileScore);
	candidate.setGradeScore(gradeScore);
	candidate.setEducationStatus(educationStatus);
	
	return candidate;
}

double getCandidateScore(Candidate candidate,
							int cppDevelopmentScoreWeight,
							int OSScoreWight,
							int experienceScoreWeight,
							int agileScoreWeight,
							int gradeScoreWeight,
							int educationStatusWeight){
	return (( candidate.getCPPDevelopmentScore() * cppDevelopmentScoreWeight ) +
								(candidate.getOSScore() * OSScoreWight) + 
								(candidate.getExperienceScore() * experienceScoreWeight) +
								(candidate.getAgileScore() * agileScoreWeight) +
								(candidate.getGradeScore() * gradeScoreWeight) +
								(candidate.getEducationStatus() * educationStatusWeight)) / 
								(cppDevelopmentScoreWeight + OSScoreWight + experienceScoreWeight + agileScoreWeight + gradeScoreWeight + educationStatusWeight);
}

Candidate getBestCandidate(deque<Candidate> candidates, 
							int cppDevelopmentScoreWeight,
							int OSScoreWight,
							int experienceScoreWeight,
							int agileScoreWeight,
							int gradeScoreWeight,
							int educationStatusWeight){
	Candidate bestCandidate = candidates[0];
	double bestCandidateScore = getCandidateScore(bestCandidate, cppDevelopmentScoreWeight, OSScoreWight, experienceScoreWeight, agileScoreWeight, gradeScoreWeight, educationStatusWeight);
	
								
	for (int i = 1; i < candidates.size(); i++){
		double candidateScore = getCandidateScore(candidates[i], cppDevelopmentScoreWeight, OSScoreWight, experienceScoreWeight, agileScoreWeight, gradeScoreWeight, educationStatusWeight);
		if(candidateScore > bestCandidateScore){
			bestCandidate = candidates[i];
			bestCandidateScore = candidateScore;
		}
	}
	
	return bestCandidate;			
}


void bubleSort(deque<Candidate> a){
	Candidate temp("aa","bb");
	for(int i = 0; i<a.size(); i++) {
	    for(int j = i+1; j<a.size(); j++)
	    {
	        if(a[j].getCPPDevelopmentScore() < a[i].getCPPDevelopmentScore()) {
	        	temp = a[i];
	        	a[i] = a[j];
	        	a[j] = temp;
	        }
	    }
	}
}

// A function to merge the two half into a sorted data.
void Merge(deque<Candidate> a, int low, int high, int mid)
{
	// We have low to mid and mid+1 to high already sorted.
	int i, j, k;
	Candidate temp[high-low+1];
	i = low;
	k = 0;
	j = mid + 1;
 
	// Merge the two parts into temp[].
	while (i <= mid && j <= high)
	{
		if (a[i].getCPPDevelopmentScore() < a[j].getCPPDevelopmentScore())
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}
 
	// Insert all the remaining values from i to mid into temp[].
	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}
 
	// Insert all the remaining values from j to high into temp[].
	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}
 
 
	// Assign sorted data stored in temp[] to a[].
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i-low];
	}
}

// A function to split array into two parts.
void MergeSort(deque<Candidate> a, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid=(low+high)/2;
		// Split the data into two half.
		MergeSort(a, low, mid);
		MergeSort(a, mid+1, high);
 
		// Merge them to get sorted output.
		Merge(a, low, high, mid);
	}
}


int main(int argc, char** argv) {
	
	deque<Candidate> candidates;
	
	int selection = -1;
	
	int cppDevelopmentScoreWeight = 1;
	int OSScoreWight = 1;
	int experienceScoreWeight = 1;
	int agileScoreWeight = 1;
	int gradeScoreWeight = 1;
	int educationStatusWeight = 1;
	
	do{
		cout<<"\n1) Add Candidate.";
		cout<<"\n2) Search Candidate.";
		cout<<"\n3) Print CV.";
		cout<<"\n4) Print Best Candidate CV.";
		cout<<"\n5) Enter weights. (Default is 1 for all scores)";
		cout<<"\n6) List Candidates.";
		cout<<"\n7) Find Best Algorithm.";
		cout<<"\n8) Exit.\n\n";
		
		cin>>selection;
		
		switch(selection){
			case 1:
				{
					string name;
					string surname;
					int cppDevelopmentScore;  //1-10
					int OSScore; //1-10
					int experienceScore; //year 
					int agileScore; //1-10
					int gradeScore; //0-4
					int educationStatus; //1-3
					cout<<"Enter name of the candidate.\n";
					cin>>name;
					cout<<"Enter surname of the candidate.\n";
					cin>>surname;
					cout<<"Enter candidate scores.\n";
					cin>>cppDevelopmentScore>>OSScore>>experienceScore>>agileScore>>gradeScore>>educationStatus;
					candidates.push_back(generateCandidate(name, surname, cppDevelopmentScore, OSScore, experienceScore, agileScore, gradeScore, educationStatus));
					break;
				}
			case 2:
				{
					string name;
					cout<<"Enter the name of candidate you want to search. \n\n";
					cin>>name;
					
					for (int i = 0; i < candidates.size(); i++){
						if(candidates[i].getName() == name)
							cout <<"\n" + candidates[i].getName() + " " + candidates[i].getSurname() + " " <<  " \n";
					}
	        			
	        			
					break;
				}
			case 3:
				{
					string name;
					cout<<"Enter the name of candidate you want to search. \n\n";
					cin>>name;
					
					for (int i = 0; i < candidates.size(); i++){
						if(candidates[i].getName() == name)
							cout <<"\n" + candidates[i].getCV()<<  " \n";
					}
					break;	
				}
			case 4:
				{
					Candidate bestCandidate = getBestCandidate(candidates, cppDevelopmentScoreWeight, OSScoreWight, experienceScoreWeight, agileScoreWeight, gradeScoreWeight, educationStatusWeight);
					cout<<bestCandidate.getCV();
					break;
				}
			case 5:
				{
					cout<<"Enter candidate score weigths.\n";
					cin>>cppDevelopmentScoreWeight>>OSScoreWight>>experienceScoreWeight>>agileScoreWeight>>gradeScoreWeight>>educationStatusWeight;
					cout<<"Score weights saved.\n";
					break;
				}
			case 6:
				{
					for (int i = 0; i < candidates.size(); i++){
						cout <<"\n" + candidates[i].getName() + " " + candidates[i].getSurname() + ": "<<candidates[i].getCPPDevelopmentScore()<<" "<<candidates[i].getOSScore()<<" "<<candidates[i].getExperienceScore()<<" "<<candidates[i].getAgileScore()<<" "<<candidates[i].getGradeScore()<<" "<<candidates[i].getEducationStatus()<<" Score -> "<<
						getCandidateScore(candidates[i], cppDevelopmentScoreWeight, OSScoreWight, experienceScoreWeight, agileScoreWeight, gradeScoreWeight, educationStatusWeight)<<" \n";
					}
					break;	
				}
			case 7:
				{
					clock_t tStart = clock();
					/*Write the function of the sorting here*/
					bubleSort(candidates);
					printf("Buble Sort Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
					tStart = clock();
					/*Write the function of the sorting here*/
					MergeSort(candidates, 0, candidates.size()-1);
					printf("Merge Sort Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
					break;
				}
			case 8:
				{
					break;
				}
			default:
				{
					cout<<"Wrong selection.\n";
				}
		}
		
	}while(selection!=8);
	
	
	
	return 0;
}




#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Candidate{
	
	private:
		string name;
		string surname;
		int cppDevelopmentScore;  //1-10
		int OSScore; //1-10
		int experienceScore; //year 
		int agileScore; //1-10
		int gradeScore; //0-4
		int educationStatus; //1-3
		/*
		int cppDevelopmentScoreWeight;
		int OSScoreWight;
		int experienceScoreWeight;
		int agileScoreWeight;
		int gradeScoreWeight;
		int educationStatusWeight;
		*/
	
	public:
		Candidate(string namee, string surnamee){
			name = namee;
			surname = surnamee;
		}
		Candidate(){
			
		}
	
	
	public:
		string getCV(){
			return "\n-------------------\n\nName: " + name +
					"\nSurname: " + surname +
					"\n\nCppDevelopmentScore: " + NumberToString(cppDevelopmentScore)+
					"\nOSScore: " + NumberToString(OSScore) +
					"\nExperienceScore: " + NumberToString(experienceScore) +
					"\nAgileScore: " + NumberToString(agileScore) +
					"\nGradeScore: " + NumberToString(gradeScore) +
					"\nEducationStatus: " + NumberToString(educationStatus) + "\n\n-----------------\n\n";
		}
	
	
	//GETTER SETTER 
	public:
	    void setName(string name) {
	      this->name = name;
	    }
	    string getName() {
	      return name;
	    }
	    void setSurname(string surname) {
	      this->surname = surname;
	    }
	    string getSurname() {
	      return surname;
	    }
	    void setCPPDevelopmentScore(int cppDevelopmentScore){
	    	this->cppDevelopmentScore = cppDevelopmentScore;
		}
		int getCPPDevelopmentScore(){
			return cppDevelopmentScore;
		}
		void setOSScore(int osScore){
			this->OSScore = osScore;
		}
		int getOSScore(){
			return OSScore;
		}
		void setExperienceScore(int experienceScore){
			this->experienceScore = experienceScore;
		}
		int getExperienceScore(){
			return experienceScore;
		}
		void setAgileScore(int agileScore){
			this->agileScore = agileScore;
		}
		int getAgileScore(){
			return agileScore;
		}
		void setGradeScore(int gradeScore){
			this->gradeScore = gradeScore;
		}
		int getGradeScore(){
			return gradeScore;
		}
		void setEducationStatus(int educationStatus){
			this->educationStatus = educationStatus;
		}
		int getEducationStatus(){
			return educationStatus;
		}
		/*/
		void setCPPDevelopmentScoreWeight(int cppDevelopmentScoreWeight){
	    	this->cppDevelopmentScoreWeight = cppDevelopmentScoreWeight;
		}
		int getCPPDevelopmentScoreWeight(){
			return cppDevelopmentScoreWeight;
		}
		void setOSScoreWeight(int osScoreWeight){
			this->OSScoreWeight = osScoreWeight;
		}
		int getOSScoreWeight(){
			return OSScoreWeight;
		}
		void setExperienceScoreWeight(int experienceScoreWeight){
			this->experienceScoreWeight = experienceScoreWeight;
		}
		int getExperienceScoreWeight(){
			return experienceScoreWeight;
		}
		void setAgileScoreWeight(int agileScoreWeight){
			this->agileScoreWeight = agileScoreWeight;
		}
		int getAgileScoreWeight(){
			return agileScoreWeight;
		}
		void setGradeScoreWeight(int gradeScoreWeight){
			this->gradeScoreWeight = gradeScoreWeight;
		}
		int getGradeScoreWeight(){
			return gradeScoreWeight;
		}
		void setEducationStatusWeight(int educationStatusWeight){
			this->educationStatusWeight = educationStatusWeight;
		}
		int getEducationStatusWeight(){
			return educationStatusWeight;
		}
		*/
		
		
		template <typename T>
		string NumberToString(T pNumber)
		{
			 ostringstream oOStrStream;
			 oOStrStream << pNumber;
			 return oOStrStream.str();
		}
};

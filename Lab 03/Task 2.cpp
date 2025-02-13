#include <iostream>
#include <string>
using namespace std;

class FitnessTracker{
	private:
    	string userName;
    	int dailyStepGoal;
    	int stepsTaken;
    	double caloriesBurned;

	public:
    	
		FitnessTracker(string name, int StepsGoal) {
        	userName=name;
        	dailyStepGoal=StepsGoal;
        	stepsTaken=0;
        	caloriesBurned=0;
    	}
		
		void CaloriesCalculator() {
        	caloriesBurned=stepsTaken*0.05; // average burn on steps taken
    	}

    	void logSteps(int steps) {
        	stepsTaken=stepsTaken+steps;
        	CaloriesCalculator();
    	}
    	

    	void DisplayDailyProgress() {
    		cout<<"--------------------------------"<<endl;
			cout<<"    Displaying Progress  "<<endl;
			cout<<"--------------------------------"<<endl;
        	cout<<"Name: "<<userName<<endl;
			cout<<"Steps Taken: "<<stepsTaken<<endl;
			cout<<"Calories Burned: "<<caloriesBurned<<endl;
			cout<<"Step Goals for the Day: "<<dailyStepGoal<<endl;
        	if(stepsTaken>=dailyStepGoal){
        		cout<<"Congratulations You have Achieved your Goal!!!"<<endl;
			}	
        	else{
        		cout<<"OOPS!!! Your Goal is not met... "<<endl;
			}
			cout<<"--------------------------------"<<endl;
            	
    	}
};

int main() {
    FitnessTracker X1("Mujtaba",1500);
    X1.logSteps(2000);
    X1.DisplayDailyProgress();
    X1.logSteps(1000);
    X1.DisplayDailyProgress();
    FitnessTracker X2("Ahmed",1000);
    X2.logSteps(2000);
    X2.DisplayDailyProgress();
    return 0;
}



class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int>stud;
        stack<int>sand;
        for(int i=0;i<students.size();i++){
            stud.push(students[i]);
        }
        for(int i=sandwiches.size()-1;i>=0;i--){
            sand.push(sandwiches[i]);
        }
        int c=0;
        while(!stud.empty() && c<stud.size()){
            if(stud.front()==sand.top()){
                stud.pop();
                sand.pop();
                c=0;
            }else{
                int front=stud.front();
                stud.pop();
                c++;
                stud.push(front);
            }
        }
        
        return stud.size();
        
    }
};

class Solution {
public:
    int candy(vector<int>& ratings) {
        //greedy--slope based intution
        
        int sum=1;
        int i=1;
        int n=ratings.size();

        while(i<n){
            if(ratings[i]==ratings[i-1]){
                sum=sum+1;
                i++;
                continue;
            }
            
            //for increasing slope
            int peak=1;
            while(i<n && ratings[i]>ratings[i-1]){
                peak=peak+1;
                sum+=peak;
                i++;
            }

            //for decreasing slope

            // if you are taking down=1,then its getting redundantly added like in  we are adding 2 instead of 1 and at last we are adding 7 also so in down we are adding 2+3+4+5+6+7 and down>peak so 7-4=3 also.. So we have to add 7 only one time so if we start by down=0 then 7 will not be added and the sum in down slope will be 1+2+3+4+5+6 then 7-4=3 giving the desired answer...
            int down=0;
            while(i<n && ratings[i]<ratings[i-1]){
                down=down+1;
                sum+=down;
                i++;
            }
            down++;

            if(down>peak){
                sum+=down-peak;
            }
        }

        return sum;

    }
};
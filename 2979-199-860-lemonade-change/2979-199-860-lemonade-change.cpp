class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0;
        int ten=0;

        //no need to declare twenty

        for(int i=0;i<bills.size();i++){
            if(bills[i]==5) five++;

            else if(bills[i]==10){
                if(five){
                    five--;
                    ten++;
                }

                else{
                    return false;
                }
            }

            else{
                //when 20 comes
                if(five && ten){
                    five--;
                    ten--;
                }

                else if(five>=3){
                    five-=3;
                }

                else{
                    return false;
                }
            }
        }
        return true; 
    }
};
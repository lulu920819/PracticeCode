class Solution {
public:
    vector<int> countBits(int num) {
        int i = 1;
        vector<int> result;
        if(num >= 0)
            result.push_back(0);
        if(num>=1)
            result.push_back(1);
        int end = pow(2,i+1);
        while(num>=end-1)
        {
            int begin = pow(2,i);
            int j=0;
            for(int k = begin;k<=end-1;k++)
            {
                result.push_back(result[j]+1);
                j++;
            }
            i++;
            end = pow(2,i+1);

        }

        int j=0;
        for(int k = pow(2,i);k<=num;k++)
        {
            result.push_back(result[j]+1);
            j++;
        }

        return result;

    }
};

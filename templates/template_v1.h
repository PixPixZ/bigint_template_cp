/*
    credit: none
    template xu li so lon (v1)

    made by hungg_261
*/
typedef string bigint;
namespace BIGINT{
    int compare(const string&a,const string&b){
        if(a.size()!=b.size())return a.size()>b.size()?1:-1;
        return a.compare(b);
    }

    string add(const string&a,const string&b){
        string result;
        int carry=0;
        int i=a.size()-1,j=b.size()-1;

        while (i>=0|j>=0||carry){
            int sum=carry;
            if(i>=0)sum+=a[i--]-'0';
            if(j>=0)sum+=b[j--]-'0';
            carry=sum/10;
            result+=sum%10+'0';
        }

        reverse(begin(result),end(result));
        return result;
    }

    string subtract(string a,string b){
        bool negative=false;
        switch(compare(a,b)){
            case -1:
                swap(a,b);
                negative=true;
                break;
            case 0:
                return "0";
        }

        string result;
        int borrow=0;
        int i=a.size()-1,j=b.size()-1;

        while (i>=0||j>=0||borrow){
            int diff=(i>=0?a[i--]-'0':0)-(j>=0?b[j--]-'0':0)-borrow;
            borrow=diff<0;
            if(borrow)diff+=10;
            result+=diff+'0';
        }

        while (result.size()>1&&result.back()=='0')result.pop_back();
        reverse(result.begin(),result.end());

        if(negative)result='-'+result;
        return result;
    }

    string multiply(const string&a,const string&b){
        vector<int>result(a.size()+b.size(),0);

        for (int i=a.size()-1;i>=0;--i){
            for (int j=b.size()-1;j>=0;--j){
                int mul=(a[i]-'0')*(b[j]-'0');
                int sum=mul+result[i+j+1];
                result[i+j+1]=sum%10;
                result[i+j]+=sum/10;
            }
        }

        string product;
        for (int num:result){
            if(!(product.empty()&&num==0))product+=num+'0';
        }

        return product.empty()?"0":product;
    }

    string divide(const string&a,const string&b){
        string result,rem;

        for (char digit:a){
            rem+=digit;
            while (rem.size()>1&&rem[0]=='0')rem.erase(0,1);

            int count=0;
            while (compare(rem,b)>=0){
                rem=subtract(rem,b);
                ++count;
            }

            result+=count+'0';
        }

        while (result.size()>1&&result[0]=='0')result.erase(0,1);
        return result.empty()?"0":result;
    }

    string modulo(const string&a,const string&b){
        return subtract(a,multiply(b,divide(a,b)));
    }
}
using namespace BIGINT;

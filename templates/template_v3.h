/*
    credit: thay Truong Phuoc Hai - PTNK
    template xu li so lon (v3)

    modified by hungg_261
*/
typedef vector<int> bigint;
namespace BIGINT_v3{
    namespace Assignment{
        template<typename _Number>
        void bigint_assign(bigint &object, _Number value){
            object.clear();
            while(value>0){
                object.push_back(value%10);
                value/=10;
            }
        }

        void bigint_assign(bigint &object, const string &value){
            object.clear();
            for (auto it = value.rbegin(); it != value.rend(); ++it) {
                object.push_back(*it-'0');
            }
        }

        void bigint_assign(bigint &object, const char*value){
            bigint_assign(object,string(value));
        }

        void bigint_assign(bigint &object, const bigint &value){
            object = value;
        }

        template<typename _Number>
        bigint bigint_make(_Number value){
            bigint object;
            while(value>0){
                object.push_back(value%10);
                value/=10;
            }
            return object;
        }

        bigint bigint_make(const string &value){
            bigint object;
            for (auto it = value.rbegin(); it != value.rend(); ++it) {
                object.push_back(*it-'0');
            }
            return object;
        }

        bigint bigint_make(const char*value){
            return bigint_make(string(value));
        }

        bigint bigint_make(const bigint &value){
            bigint object = value;
            return object;
        }
    }
    using namespace Assignment;

    istream& operator>>(istream& in, vector<int>& vec) {
        string num;
        in >> num;

        while (num.size()>0) {
            vec.push_back(num.back()-'0');
            num.pop_back();
        }
        return in;
    }

    ostream& operator<<(ostream& out, const vector<int>& vec) {
        for (auto it = vec.rbegin(); it != vec.rend(); ++it) {
            out << *it;
        }
        return out;
    }

    bigint operator + (bigint a, bigint b)
    {
        bigint res;
        int i = 0, j = 0, cr = 0;
        while (i < a.size() | j < b.size())
        {
            if (i < a.size())
            cr = cr + a[i++];
            if (j < b.size())
            cr = cr + b[j++];
            res.push_back(cr%10);
            cr = cr / 10;
        }
        if (cr > 0) res.push_back(cr);
        return res;
    }

    // điều kiện a >= b
    bigint operator - (bigint a, bigint b)
    {
        bigint res;
        int i = 0, j = 0, cr = 0;
        while (i < a.size() || j < b.size())
        {
            int c = a[i++] - cr;
            if (j < b.size()) c = c - b[j++];
            if (c < 0)
            {
                c = c + 10;
                cr = 1;
            }
                else cr = 0;
                res.push_back(c);
            }
        while (res.back() == 0) res.pop_back(); // loại bỏ chữ số 0 vô nghĩa
        if(res.empty())res.push_back(0);
        return res;
    }

    bigint operator * (bigint a, int b)
    {
        bigint res;
        int cr = 0;
        for (int i = 0; i < a.size(); ++i)
        {
            cr = cr + a[i]*b;
            res.push_back(cr % 10);
            cr = cr / 10;
        }
    if (cr > 0) res.push_back(cr);
    return res;
    }

    //hàm cho kết quả của a*10^n
    bigint mul10(bigint a, int n)
    {
        bigint res(a.size()+n, 0);
        for (int i = 0, j = n; i < a.size(); ++i, ++j)
            res[j] = a[i];
        return res;
    }

    bigint operator * (bigint a, bigint b)
    {
        bigint res;
        for (int i = 0; i < b.size(); ++i)
        {
            // tái sử dụng phép nhân với số nguyên có 1 chữ số
            bigint c = a*b[i];
            c = mul10(c, i);
            res = res + c;
        }
        return res;
    }

    // that dang tiec thay, khong co ham chia (/) :'<
}
using namespace BIGINT_v3;

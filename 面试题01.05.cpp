class Solution {
public:
    bool oneEditAway(string first, string second) {
        int length1 = first.size(), length2 = second.size();
        if(length1 == length2) {
            bool flag = false;
            for(int i=0; i<length1; i++) {
                if(first[i] != second[i]) {
                    if(!flag) {
                        flag = true;
                        cout<<"first time"<<endl;
                    } else {
                        cout<<"second time"<<endl;
                        return false;
                    }
                }
            }
            return true;
        } else if(length1-length2 == 1 || length2-length1 == 1) {
            if(length1 > length2) {
                return check_ok(first, second);
            } else {
                return check_ok(second, first);
            }
        } else {
            return false;
        }
    }
    bool check_ok(string& longer, string& shorter) {
        int ptr1, ptr2;
        for(ptr1 = 0, ptr2 = 0; ptr1 < longer.size(); ptr1++) {
            if(longer[ptr1] == shorter[ptr2]) {
                cout<<shorter[ptr2]<<endl;
                ptr2++;
            }
        }
        if(ptr1-ptr2 > 1) {
            return false;
        }
        else return true;
    }
};
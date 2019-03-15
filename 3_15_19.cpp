#include <iostream>
#include <vector>

using namespace std;

class IDLog {
    vector<int> ids;
    
public:
    IDLog(int first_order);
    void record(int order_id);
    int get_last(int i);
    
    
};

IDLog::IDLog(int first_order){
    ids.push_back(first_order);
}

void IDLog::record(int order_id){
    ids.push_back(order_id);
}

int IDLog::get_last(int i){
    return ids[i];
}

int main()
{
    
    IDLog log1(1);
    log1.record(2);
    
    cout << log1.get_last(1) << "\n";
    
    system("Pause");
    return 0;
}
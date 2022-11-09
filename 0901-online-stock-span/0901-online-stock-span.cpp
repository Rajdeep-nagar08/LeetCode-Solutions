class StockSpanner {
    stack<pair<int, int>> storage;
    int index = 0;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        if (storage.empty()) {
            storage.push({price, index++});
            return 1;
        } else {
            while (!storage.empty() && price >= storage.top().first) {
                storage.pop();
            }
            int res = 0;
            res = storage.empty() ? index + 1 : index - storage.top().second;
            storage.push({price, index++});
            return res;
        }
    }
};
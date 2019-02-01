int getMaxProfit(const vector<int>& stockPrices)
{
    if (stockPrices.size() <2) throw "BURP";
    // calculate the max profit
    int minl = INT_MAX;
    int maxr = 0;
    int delta = INT_MIN;
    int i=0;
    
    while ( i<stockPrices.size()) {
       if (stockPrices[i] < minl) minl = stockPrices[i];
           
       i++;
       if (i==stockPrices.size()) break;
        maxr = stockPrices[i];
        delta = max(delta,maxr-minl);
    }

    return delta;
}



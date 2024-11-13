#include<iostream>
#include<string>
using namespace std;
const int MAX_SIZE = 30;  // 陣列最大長度

template<typename T>
int Binary_Search(T arr[], int size, T target)
{
    int l = 0;//左
    int r = size - 1;//右
    while (l <= r)
    {
        int m = (l + r) / 2;//中間值
        if (arr[m] == target) return m;//找到，回傳位置
        else if (arr[m] > target) r = m - 1;//繼續在左半部搜尋
        else l = m + 1;//繼續在右半部搜尋
    }
    return -1;//找不到
}
int main()
{
    char T;
    int n, q,x;
    while (true)
    {
        cout << "請輸入一字元和兩正整數:";
        cin >> T >> n >> q;
        while(n < q || n > MAX_SIZE || q < 1 || q > n)
        {
            cout << "輸入錯誤！請重新輸入一字元和兩正整數:";
            cin >> T >> n >> q;
            continue;
        }
        if (T == 'i')//處理整數搜尋
        {
            int arr[MAX_SIZE];
            cout << "請輸入" << n << "個整數值:";
            for (int i = 0; i < n; i++)
            {
                cin >> arr[i];
            }
            cout << "請輸入要搜尋的值:";
            for (int i = 0; i < q; i++)//輸入欲查詢的值，並呼叫Binary_Search的函式模板進行搜尋
            {
                int  target;
                cin >> target;
                int result = Binary_Search<int>(arr, n, target);
                cout << result << endl;
            }
        }
        else if (T == 's')////處理字串搜尋
        {
            string arr[MAX_SIZE];
            cout << "請輸入" << n << "個字串:";
            for (int i = 0; i < n; i++)
            {
                cin >> arr[i];
            }
            cout << "請輸入要搜尋的字串:";
            for (int i = 0; i < q; i++)//輸入欲查詢的字串，並呼叫Binary_Search的函式模板進行搜尋
            {
                string target;
                cin >> target;
                int result = Binary_Search<string>(arr, n, target);
                cout << result << endl;
            }
        }
        else
            cout << "不支援此類型"<<endl;
    }
    return 0;
}
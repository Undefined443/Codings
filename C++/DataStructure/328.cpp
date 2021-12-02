#include <iostream>

using namespace std;

int *hash_table{}; //0 表示该位置为空，-1 表示该位置元素被删除

int m, p; //哈希表表长和除数

size_t get_hash(int key) {
    size_t hash_address = key % p;
    while (hash_table[hash_address]) {
        if (hash_table[hash_address] == key) { //查找成功
            return hash_address;
        }
        ++hash_address;
        hash_address %= m;
    } //查找失败，插入 key
    if (hash_table[m] == m - 1) { //若表满
        return m + 1;
    }
    hash_table[hash_address] = key;
    ++hash_table[m];
    return hash_address;
}

int main() {
    cin >> m >> p;
    hash_table = new int[m + 1]{}; //用最后一个元素存储元素个数
    int key;
    while (cin >> key, key != -1) {
        size_t address = get_hash(key);
        if (address != m + 1) {
            cout << address << endl;
        } else {
            cout << "Table full";
            return 0;
        }
    }
}
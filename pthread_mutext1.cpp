/*************************************************************************
	> File Name: pthread_mutext1.cpp
	> Author: liyz
	> Mail: 981530280@qq.com 
	> Created Time: 2019年06月22日 星期六 15时33分14秒
 ************************************************************************/

#include <iostream>
#include <map>
#include <cstring>
#include <stdio.h>
#include <pthread.h>
using namespace std;
template<typename K, typename V>
class HashMap
{
public:
    HashMap()
    {
        pthread_mutex_init(&f_mutex, NULL);
    }
    ~HashMap()
    {
        pthread_mutex_destroy(&f_mutex);
    }
public:
    int hashmap_insert(K key, V val)
    {
        int iret = 0;
        pthread_mutex_lock(&f_mutex);
        f_hashmap.insert(std::pair<K, V>(key, val));
        pthread_mutex_unlock(&f_mutex);
        return iret;
    }
    int hashmap_find(K key, V &val)
    {
        pthread_mutex_lock(&f_mutex);
        f_iterator = f_hashmap.find(key);
        if(f_iterator == f_hashmap.end())
        {
            pthread_mutex_unlock(&f_mutex);
            return -1;
        }
        val = f_iterator->second;
        pthread_mutex_unlock(&f_mutex);
        return 0;
    }
    int hashmap_clear()
    {
        int ret = 0;
        pthread_mutex_lock(&f_mutex);
        f_hashmap.clear();
        pthread_mutex_unlock(&f_mutex);
        return ret;
    }
    int hashmap_earse(K key)
    { 
        int ret = 0;
        pthread_mutex_lock(&f_mutex);
        f_hashmap.erase(key);
        pthread_mutex_unlock(&f_mutex);
        return ret;
    }
	int hashmap_printf()
	{
		pthread_mutex_lock(&f_mutex);
		for(f_iterator = f_hashmap.begin(); f_iterator != f_hashmap.end();f_iterator++)
        {
            cout << f_iterator->first << endl;
            cout << f_iterator->second <<  endl;
        }
        pthread_mutex_unlock(&f_mutex);
        return 0;
	}

private:
    std::map<K, V> f_hashmap;
    typename std::map<K, V>::iterator f_iterator;
    pthread_mutex_t f_mutex;
};
HashMap<string, int > myhash;

int main()
{
    int i = -1;
    int size = 64;
    string buf = "开门";
	myhash.hashmap_insert(buf,0);
    myhash.hashmap_printf();
    myhash.hashmap_find("开门",i);
    printf("%d\n", i);
    if(i > size - 1)
    {
        cout << "helloworld" << endl;
    }
    return 0;
}

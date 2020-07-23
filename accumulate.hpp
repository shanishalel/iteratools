#pragma once
#include <iostream>
#include <vector>
#include <iterator>


/* 
lambda function - we can change the struct to lambada function
[](int x, int y){return x+y;}
*/

//fucntor binary that represent add function
typedef struct{
    template<typename T> 
    auto operator()(const T& x, const T& y)const{
        return x+y;
    }
}plus;

/*
1.get container and return new container that contain
partion sum .
accumulate(range(5,9))= (5, 5+6, 5+6+7, 5+6+7+8,5+6+7+8+9) 
2.gets container and a binary functor and use him instead of +
accumulate(vector({5,6,7,8}))= (5, 5+6, 5+6+7, 5+6+7+8,5+6+7+8+9)*/

namespace itertools{
    //by default gets the add functor
    template <class T, class FUNCTOR=plus> 
    class accumulate {
        const T& container;
        const FUNCTOR& function;

        public:
        //default
        accumulate (const T& cont,const FUNCTOR& fun=plus()):container(cont), function(fun){}

        
        class iterator{
            
            decltype (container.begin()) curr; //restart iterator
            typename std:: decay<decltype(*(container.begin()))>::type p_sum; //restart the container
            const accumulate& ac; // a reference to accumulate

            public:
            iterator(decltype(container.begin())iter, const accumulate& acc): curr(iter), ac(acc){ 
                if(iter!=acc.container.end()) p_sum=*iter;
            }

            //++i
            iterator& operator++(){
                ++curr;
                if(curr==ac.container.end()) return *this; //end
                p_sum=ac.function(p_sum,*(curr)); //promote the curr by the p_sum and the function
                return *this;
            }
            
            //i++
            const iterator operator++ (int){
                iterator temp= *this;
                p_sum=ac.function(p_sum,*(curr++)); //promote the curr by the p_sum and the function
                return temp;
            }

            //retrun true if it == curr
            bool operator==(const iterator &it) const{
                return curr==it.curr;
            }

            //return the iterator
            iterator& operator=(const iterator &it) {
                return *this;
            }

            //return false if it!=curr
            bool operator!=(const iterator &it) const{
                return curr!=it.curr;
            }

            //return the p_sum
            auto operator*(){
                return p_sum;
            }
            
        };
    
        //return  iterator initalize to begin
        iterator begin() const{
            return iterator(container.begin(), *this);
        }

        //return  iterator initalize to end
        iterator end()const{
            return iterator(container.end(), *this);

        }

    };
}

#pragma once
#include <iostream>

/*get 2 container that has the same length the first
contain structs and the second contains boolean structs.
return containers that has an verbs from the first containers
that the verbs that fit to them is in the second containers 
compress(range(5,9),vector({true,true,false,true})) =(8,6,5)*/
namespace itertools{
    //gets 2 containers
    template<class con1, class con2>
    class compress{
        const con1& container1;
        const con2& container2;

        public:
        //defualt
        compress( const con1& t1,  const con2& t2 ): container1(t1), container2(t2){}

        class iterator{
            decltype(container1.begin()) iter1; //initalize the container
            decltype(container2.begin()) iter2; //initalize the container
            const compress& compr; //reference to compress

            public:
            
            iterator(decltype(container1.begin()) it1,decltype(container2.begin()) it2, const compress& com):
            iter1(it1), iter2(it2), compr(com){
                //if the secound only last
                if(iter2!=com.container2.end())iter2=it2;

                while(iter2!=compr.container2.end() && *iter2==false){
                    iter1++;
                    iter2++;
                }

            }

            iterator& operator++(){
                ++iter1;
                ++iter2;
                //iter 2 isn't in the end and iter2 is false pass until it true
                while(iter2!=compr.container2.end() && *iter2==false){
                    iter1++;
                    iter2++;
                }
                return *this;
            }

            
            const iterator operator++(int){
                iterator temp=*this;
                ++iter1;
                ++iter2;
                return temp;
            }

            bool operator==(const iterator& it)const{
                return iter1==it.iter1;
            }

            bool operator!=(const iterator& it)const{
                return iter1!=it.iter1;
            }
            
            auto operator*(){
                return *iter1;
            }

        };

        //return iterator initialize to begin
        iterator begin() const{
            return iterator(container1.begin(), container2.begin(),*this);
        } 

        //return iterator initialize to end
         iterator end() const{
            return iterator(container1.end(), container2.end(),*this);
        }
    };
}

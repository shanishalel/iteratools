#pragma once
namespace itertools{

/* gets two real numbers and represnts all the numbers between
the first to the last */
    class range{
        int start;
        int n_end;

        public:
        //default instructor
        range(int a,int b):start(a),n_end(b){}

        class iterator{
            int current;  //an int in the range between start to end

            public:
                iterator(int curr=0):current(curr){} //initialize curr

                //every iterator should have operators: ++, ==, !=, *
               //++i
                iterator &operator++(){
                  current=current+1;
                  return *this;      
                }
                //i++
                iterator operator++(int){
                  iterator temp=*this;
                  current= current+1;
                  return temp;  
                }

                //retrun true if temp==current
                bool operator ==(const iterator &temp)const{
                    return current==temp.current;
                }

                //retrun true if temp!=current
                bool operator!=(const iterator &temp)const{
                    return current != temp.current;
                }

                int operator*(){
                    return current;
                }
            
        };

        //return iterator initilize to start
        iterator begin() const{
            return iterator(start);
        }

        //return iterator initilize to end
         iterator end() const {
          return iterator(n_end);
      }
    };
} 
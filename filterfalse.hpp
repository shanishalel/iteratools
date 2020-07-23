#pragma once

/* gets boolean functor and container. return new container
that contain only the vebs that aren't exist by the boolean functor */
namespace itertools{
    
    template <typename FUNCTOR, typename T>//gets boolean functor and a container

    class filterfalse{
        const T& container;
        const FUNCTOR& func;

        public:
        
        filterfalse(const FUNCTOR& fun, const T&con):func(fun), container(con){} //default constructor

        class iterator{
            decltype(container.begin())iter; //intialize the container
            const filterfalse& fil; //referencr to filterfalse
            
            public:
            iterator(decltype(container.begin())it,  const filterfalse& filter): iter(it), fil(filter){
               // ++ until the number is not fulfill the functor  
                while(iter!=fil.container.end() && fil.func(*iter))iter++; 
             }

            //++i
            iterator& operator++(){
                ++iter;
                // ++ until the number is not fulfill the functor
                while(iter!=fil.container.end() && fil.func(*iter))iter++;
                return *this;
            }

            //i++
            const iterator operator++(int){
                iterator temp=*this;
                ++iter;
                return temp;
            }

            
            bool operator==(const iterator& it)const{
                return iter==it.iter;
            }

            bool operator!=(const iterator& it)const{
                return iter!=it.iter;
            }

            auto operator*(){
                return *iter;
            }

        };

        //return iterator initialize to begin
        iterator begin() const{
            return iterator(container.begin(), *this);
        }

         //return iterator initialize to end
        iterator end() const{
            return iterator(container.end(), *this);
        }



    };
}
#pragma once

#include "./iterator_traits.hpp"
#include "./iterator_baseClass.hpp"
#include "./is_integral.hpp"
#include "./remove_cv.hpp"
#include "./struct_node.hpp"
#include "./pair_make_pair.hpp"

namespace ft
{
    template <typename key, class value, bool _const = false>
    class mapIterator
    {
        public:
            /* Shorthands and definitions */
            typedef          mapIterator<key, value, _const>                                    auto_class;
            typedef          ft::pair<const key, value>                                         value_type;
			typedef 		 ft::iterator<std::bidirectional_iterator_tag, value_type>  		standard;
            typedef typename standard::difference_type      						            difference_type;
            typedef typename standard::iterator_category    						            iterator_category;
            typedef typename standard::pointer              						            pointer;
            typedef typename standard::reference            						            reference;
            typedef			ft::Node<value_type>*												ptr_n;
            
            /* Constructors and Destructors */
            mapIterator() : _ptr(NULL) {}
            mapIterator(ptr_n ptr) : _ptr(ptr) {}
            mapIterator(const mapIterator<typename remove_cv<value_type>::type, value, _const> &other) : _ptr(other.getPtr()) {}
            virtual ~mapIterator() {} // virtual destructor : why?

            /* Retrieve the current ptr_n */
            // ptr_n base() const { return this->_ptr;};
            
            /* Comparison Operators */
            mapIterator &operator=(const mapIterator<typename remove_cv<value_type>::type, value, _const> &other)
            {
            //     if (this != &other)
                _ptr = other.getPtr();
                return *this;
            }

            template <typename T1>
			bool operator==(const T1& s) const {

				return _ptr == s.getPtr();
			}

			template <typename T1>
			bool operator!=(const T1& s) const {
				
				return _ptr != s._ptr;
			}

            /* Operators */
            reference operator*() const {return _ptr->pair_node; } // OK
            pointer operator->() const { return &_ptr->pair_node; } // OK
            mapIterator &operator++()
            {
				if (_ptr == max(*_ptr->node_base))
                {
                    //std::cout << "je rentre ici " << std::endl;
					_ptr = *_ptr->node_sent;
                }
				else
					_ptr = right_after(_ptr);
				return *this; 
            } // OK

            mapIterator operator++(int) 
            { 
                mapIterator tmp(*this); 
				if (_ptr == max(*_ptr->node_base))
					_ptr = *_ptr->node_sent;
				else
					_ptr = right_after(_ptr);
				return tmp;
            } // OK
            
            mapIterator &operator--() 
            {
                if (_ptr == min(*_ptr->node_base))
                    _ptr = *_ptr->node_sent;
                else if (_ptr == *_ptr->node_sent)
                    _ptr == max(*_ptr->node_base);
				else
					_ptr = right_before(_ptr);
				return *this;
            } // OK prefix --
 
            mapIterator operator--(int)
            {
                mapIterator tmp(*this);

               if (_ptr == min(*_ptr->node_base))
                    _ptr = *_ptr->node_sent;
                else if (_ptr == *_ptr->node_sent)
                    _ptr == max(*_ptr->node_base);
				else
					_ptr = right_before(_ptr);
				return tmp;
            } // OK postfix --

        	private:
          		ptr_n _ptr; // ptr_n to the current node

            /*************************************************************************/
            /*                Functions that help : 	    	                	*/
            /* *********************************************************************/

            ptr_n min(ptr_n node)
            {
				while (node->left != *_ptr->node_sent)
					node = node->left;
				return node;
            }

            ptr_n max(ptr_n node)
            {
				while (node->right != *_ptr->node_sent)
					node = node->right;
				return node;
            }

            ptr_n right_after(ptr_n x) {
				if (x->right != *_ptr->node_sent)
					return min(x->right);
				ptr_n y = x->parent;
				while (y != *_ptr->node_sent && x == y->right)
				{
					x = y;
					y = y->parent;
				}
				return y;
			}

            ptr_n right_before(ptr_n x) {
				if (x->left != *_ptr->node_sent)
					return max(x->left);
				ptr_n y = x->parent;
				while (y != *_ptr->node_sent && x == y->left)
				{
					x = y;
					y = y->parent;
				}
				return y;
			}

            ptr_n getPtr() {
				return (_ptr);
			}
        };
}
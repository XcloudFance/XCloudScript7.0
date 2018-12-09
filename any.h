/*!
* \file basic.h
*
* \author erow
* \date ���� 2016
*
*   ���������������
*/

#pragma once
#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
using namespace std;

class __base_type {
public:
    virtual const char* get_id_name() = 0;//��֤��������
};
/*!
* \class real_type
*
* \brief ����ʵ�壺��Ҫʹ����ģ����������
*
* \author erow
* \date ���� 2016
*/
template<class T>
class real_type :public __base_type
{
public:
    const T&  get_value() {
        return m_data;
    }
    const char* get_id_name() { return typeid(T).name(); }

    void assign(const T& data) { m_data = data; }
    real_type() {}
    ~real_type() {}

private:
    T m_data;
};
/*!
 * \class virtual_type
 *
 * \ingroup microcloud
 *
 * \brief boost:any.can accept any type 
 *
 * USEAGE: 
 string str="asd";
 virtual_type vs = str, vs1;
 vs1 = vs;
 cout << vs.cast<string>() << endl;
 cout << vs1.cast<string>();
 *
 * \note There are maybe some mistakes
 *
 * \author erow
 *
 * \version 1.0
 *
 * \date ���� 2016
 *
 * Contact: clouderow@gmail.com
 *
 */
class virtual_type {
public:
    virtual_type() :policyPtr(nullptr) {}
    virtual_type(const virtual_type& x)
    {
        policyPtr = x.policyPtr;
    }

    const virtual_type& operator=(const virtual_type& x)
    {
        policyPtr = x.policyPtr;
        return *this;
    }
    template<typename T>
    virtual_type(const T& x) {
        policyPtr = std::make_shared<real_type<T> >();
        (static_cast<real_type<T>*>(policyPtr.get()))->assign(x);
    }
    template<typename T>
    const virtual_type& operator=(const T& x) {

        policyPtr = std::make_shared<real_type<T> >() ;
        (static_cast<real_type<T>*>(policyPtr.get()))->assign(x);
        return *this;
    }
    /*!
    * \brief cast ���ص���һ������
    */
    template<typename T>
    T cast() 
    {
        //cout << typeid(T).name() << "\n" << policyPtr->get_id_name();
        if (policyPtr!=nullptr) 
        { 
           // assert(strcmp(typeid(T).name(), policyPtr->get_id_name()) == 0);//ȷ��������ͬ
          
            return (static_cast<real_type<T>*>(policyPtr.get()))->get_value();
        }
        throw std::exception("nullptr");
        return T();
    }
    /*!
    * \brief modify �޸�����
    */
    template<typename T>
    void modify(const T& data)
    {
        if (policyPtr != nullptr)
        {
        //assert(strcmp(typeid(T).name(), policyPtr->get_id_name()) == 0);
        (static_cast<real_type<T>*>(policyPtr.get()))->assign(data);
        }
        else        throw std::exception("nullptr");

    }
    bool is_empty() {
        return policyPtr == nullptr;
    }

    ~virtual_type() {

    }
    void print_type()
    {
        cout << policyPtr->get_id_name() << std::endl;
    }
private:

    shared_ptr<__base_type> policyPtr;

};

 

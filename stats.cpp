#include "stats.h"
#include <cassert>
#include <assert.h>
using namespace std;
namespace main_savitch_2C{
    
statistician::statistician():count(0),total(0){   //constructor
}

void statistician::next(double r)
{
    if(count <= 0) 
    {
        count = 1;
        total = r;
        tinyest = r;
        largest = r;
        return;
    }
        count++;
        total += r;

        if(r < tinyest) {
            tinyest = r;
        }
        if(largest < r) {
            largest = r;
        }
}

void statistician::reset()
{
    count= 0;
    total = 0;
}

int statistician::length( ) const{
    return count;
}

double statistician::sum( ) const{
    return total;
}

double statistician::mean( ) const{
    double average;
    assert (count > 0);
    average = total/count;

    return average;
}

double statistician::minimum( ) const{
    assert(count>0);
    return tinyest;
}
double statistician::maximum( ) const{
    assert(count>0);
    return largest;
}

statistician operator+ (const statistician& s1, const statistician& s2)
{
if(s1.count==0 && s2.count>0){
    statistician result1=s2;
    return result1;
}
else if(s2.count==0 && s1.count>0){
    statistician result2=s1;
    return result2;
}
else if(s2.count==0 && s1.count==0){
    statistician a=s1;
    return a;
}else
{
statistician res;
res.total= s1.total + s2.total;
res.count=(s1.count+s2.count);
if(s1.maximum()>=s2.maximum())
    res.largest=s1.maximum();
if(s1.maximum()<=s2.maximum())
    res.largest=s2.maximum();
if(s1.minimum()<=s2.minimum())
    res.tinyest=s1.minimum();
if(s1.minimum()>=s2.minimum())
    res.tinyest=s2.minimum();
    return res;
}


}
statistician operator* (double scale, const statistician& s)
{
    
    statistician result; 
    result.count=s.count;
    if(scale>0)
    {
        result.total=scale*s.total;
        result.tinyest=s.tinyest*scale;
        result.largest=s.largest*scale;
    }else
    if(scale<0)
    {
        result.total=s.total*scale;
        result.largest=s.tinyest*scale;
        result.tinyest=s.largest*scale;
    }else
    if(scale==0)
    {
        result.total=0;
        result.tinyest=0;
        result.largest=0;
    }
    return result;
}

bool operator ==(const statistician& s1, const statistician& s2)
{
    if(s1.length()==0 && s2.length()==0)
        return true;
    return(s1.length()==s2.length() && s1.mean()==s2.mean() && s1.maximum()==s2.maximum() && s1.minimum()==s2.minimum() && s1.sum() ==s2.sum());
}
}

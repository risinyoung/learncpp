template <int N, typename T>
class smallVtr{
    T vr [N];
    public:
    T & operator[](int i){
        return vr[i];
    }
};


template<int M> 
struct metaDot{
    template<int N, typename T>
    static T f(smallVtr<N,T> & u, smallVtr<N,T> &v){
        return u[M-1]*v[M-1] + metaDot<M-1>::f(u,v);
    }
};

template<> 
struct metaDot<1>{
    template<int N, typename T>
    static T f(smallVtr<N,T> & u, smallVtr<N,T> &v){
        return u[0]*v[0];
    }
};

template<int N, typename T>
inline T dot(smallVtr<N,T> & u, smallVtr<N,T> & v){
    return metaDot<N>::f(u,v);
}


template<typename LeftOpd,typename Op, typename RightOpd>
struct LOR{
    LeftOpd fod;
    RightOpd rod;

    LOR(LeftOpd p, RightOpd r): fod(p), rod(r){}
    double operator[](int i){
        return Op::apply(fod[i], rod[i]);
    }
};

class Vtr{
    int length;
    double * vr;
    public:
    Vtr(int n, double * d):length(n),vr(d){}

    template<typename LeftOpd, typename Op, typename RightOpd>
    void operator=(LOR<LeftOpd, Op, RightOpd> exprn){
        for(int i = 0; i < length; i++) vr[i] = exprn[i];
    }
    double & operator[](int i) const{return vr[i];}
};

struct Multiply{
    static double apply(double a, double b){
        return a*b;
    }
};

template<typename LeftOpd>
LOR<LeftOpd, Multiply, Vtr> operator*(LeftOpd fod, Vtr rod){
    return LOR<LeftOpd, Multiply, Vtr>(fod, rod);
}
#include<bits/stdc++.h>
using namespace std;
#define MAXD 2
#define SQ(x) ((x)*(x))
const double eps=1e-9,pi=acos(-1.0);
double cosineRule3Side ( double a, double b, double c ) {
    double res = (SQ(a)+SQ(b)-SQ(c)) / (2*a*b);
    if ( res < -1 ) res = -1;
    if ( res > 1 ) res = 1;
    return acos ( res );
}
struct myVec {
    int d; //Dimension
    double val[MAXD];//Contains value of each component
    myVec() {
        d=2;
    }
    myVec(int _d,double*a) {
        d=_d;
        for(int i=0; i<d; i++) {
            val[i]=a[i];
        }
    }
    myVec(int _d,double x,double y) {
        d=_d;
        val[0]=x;
        val[1]=y;
    }
    myVec add ( myVec b ) {
        myVec res;
        for(int i=0; i<d; i++) res.val[i] = val[i] + b.val[i];
        return res;
    }
    myVec sub ( myVec b ) {
        myVec res;
        for(int i=0; i<d; i++) res.val[i] = val[i] - b.val[i];
        return res;
    }
    myVec mul ( double t ) {
        myVec res;
        for(int i=0; i<d; i++)res.val[i] = val[i] * t;
        return res;
    }
    myVec div ( double t ) {
        myVec res;
        for(int i=0; i<d; i++) res.val[i] = val[i] / t;
        return res;
    }
    bool operator == ( myVec b ) {
        for(int i=0; i<d; i++) if ( fabs ( val[i] - b.val[i] ) > eps ) return false;
        return true;
    }
    myVec perp2D() {
        myVec res = (*this);
        swap ( res.val[0], res.val[1] );
        res.val[0] *= -1;
        return res;
    }
    double dot ( myVec v ) { //Finds *this (dot) v
        double res = 0;
        for ( int i = 0; i < d; i++ ) res += val[i] * v.val[i];
        return res;
    }
    double length () { //Finds length of current vector
        return sqrt ( this->dot( *this ) );
    }
    myVec unitVec () {
        return (*this).div ( length() ); // v / ||v||
    }
    double angleBetween ( myVec b ) { //Angle between two vectors
        double res = dot( b ) / ( length() * b.length() );
        if ( res > 1 ) res = 1;
        if ( res < -1 ) res = -1;
        return acos (res);
    }
    double polarAngle2D() { //Angle from x-axis
        double res = atan2 ( val[1], val[0] );
        if ( res + eps < 0 ) res += 2 * pi;
        return res;
    }
    double cross2D ( myVec v ) { //Cross the two values. Only for 2D. Z compo 0.
        return val[0]*v.val[1] - val[1]*v.val[0];
    }
};
inline int RI() {
    int  ret = 0, flag = 1,ip = getchar_unlocked();
    for(; ip < 48 || ip > 57; ip = getchar_unlocked()) {
        if(ip == 45) {
            flag = -1;
            ip = getchar_unlocked();
            break;
        }
    }
    for(; ip > 47 && ip < 58; ip = getchar_unlocked())
        ret = ret * 10 + ip - 48 ;
    return flag * ret;
}
struct myLine {
    myVec a, b; //a is displacement, b is direction.
    //Builds a line from two points
    myLine() {}
    myLine lineFromPoints ( myVec x, myVec y ) {
        myLine m;
        m.a = x;
        m.b = y.sub ( x );
        return m;
    }
    //Finds point on line, given t.
    myVec atPos ( double t ) {
        return a.add ( b.mul ( t ) ); // a + tb;
    }
    double lineToPointDistance ( myVec p, double t ) {
        p = p.sub ( a ); //Take it to origin
        t = b.dot ( p ) / ( b.length() * b.length() ); //point of intersection
        myVec x = b.mul ( t ); //tb
        return ( p.sub(x).length() ); //xp length()
    }
    double segmentToPointDistance ( myVec p, double &t ) {
        p = p.sub ( a ); //Take it to origin
        t = b.dot ( p ) / ( b.length() * b.length() );
        if ( t + eps < 0 || t > 1 + eps ) { //Not on segment
            return min ( p.length(), p.sub(b).length() );
        }
        myVec x = b.mul ( t ); //tb
        return ( p.sub(x).length() ); //xp length()
    }
    bool overlapParallel ( myLine l ) {
        double p, q, r, s;
        if ( b.val[0] == 0 ) {
            p = a.val[1];
            q = atPos(1).val[1];
            r = l.a.val[1];
            s = l.atPos ( 1 ).val[1];
            if ( min ( r, s ) > max ( p, q ) ) return false;
            if ( max ( r, s ) < min ( p, q ) ) return false;
            return true;
        } else {
            p = a.val[0];
            q = atPos(1).val[0];
            r = l.a.val[0];
            s = l.atPos ( 1 ).val[0];
            if ( min ( r, s ) > max ( p, q ) ) return false;
            if ( max ( r, s ) < min ( p, q ) ) return false;
            return true;
        }
    }
    char lineAndLineIntersection2D ( myLine l, double &t, double &s ) {
        if ( b.cross2D ( l.b) == 0 ) {
            if ( l.a.sub(a).cross2D(l.b) == 0 ) {
                if ( overlapParallel ( l ) ) return 'o'; //overlaps
                else return 'p'; //parallel
            } else return 'd'; //disjoint and parallel
        }
        myVec w = a.sub ( l.a );
        myVec p = l.b.perp2D(), z = b.perp2D();
        t = -(w.dot(p))/p.dot(b); //for current line
        s = w.dot(z)/z.dot(l.b); //for line l
        return 'i';
    }
    double lineAndLineDistance2D ( myLine l ) {
        double t, s; //First check if the intersect
        char r = lineAndLineIntersection2D ( l, t, s );
        if ( r == 'i' ) return 0; //Intersects. 0 distance.
        //Parallel Lines
        return lineToPointDistance ( l.a, t );
    }
    double lineAndSegmentDistance2D ( myLine l ) {
        double t, s;
        char r = lineAndLineIntersection2D ( l, t, s );
        if ( r == 'i' && s + eps > 0 && s < 1 + eps ) {
            return 0; //Valid intersection
        }
        double res = lineToPointDistance ( l.a, t );
        res = min ( res, lineToPointDistance ( l.a.add(l.b), t ) );
        return res;
    }
    double segmentAndSegmentDistance2D ( myLine l ) {
        double t, s;
        char r = lineAndLineIntersection2D ( l, t, s );
        if ( r =='i' && t+eps > 0 && t < 1 + eps && s + eps > 0 && s < 1 + eps ) {
            return 0; //Valid intersection
        }
        double res = segmentToPointDistance ( l.a, t );
        res = min ( res, segmentToPointDistance ( l.a.add(l.b), t ) );
        res = min ( res, l.segmentToPointDistance ( a, t ) );
        res = min ( res, l.segmentToPointDistance ( a.add ( b ), t ) );
        return res;
    }
    myLine reflect ( myVec p, myVec norm ) {
        myVec ap = p.sub ( a ); //Starting to Point of Reflection
        norm = norm.unitVec();
        double d = fabs ( ap.dot ( norm ) );
        myVec m = p.add ( norm.mul ( d ) );
        myVec h = m.sub ( a ).mul ( 2 );
        m = a.add ( h );
        myLine ray = ray.lineFromPoints ( p, m );
        return ray;
    }
};
bool collinear ( myVec a, myVec b, myVec c ) {
    myVec ab = b.sub(a), ac = c.sub(a);
    double d = fabs ( ab.dot(ac) );
    if ( fabs ( d - ab.length() * ac.length() ) <= eps ) return true;
    return false;
}
int main() {
    int t;
    t=RI();//scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        int n;
        double ax,x,y;
        n=RI();
        ax=double(RI());
        //scanf("%d %lf",&n,&ax);
        myVec arr[n];
        for(int i=0; i<n; i++) {
            x=double(RI());
            y=double(RI());
            //scanf("%lf%lf",&x,&y);
            arr[i]=myVec(2,x,y);
        }
        myLine q;
        int ii=0;
        while(ii<n && arr[ii].val[1]<eps)ii++;
        q=q.lineFromPoints(myVec(2,ax,0),arr[ii-1]);
        double ans=0;
        for(int i=ii; i<n; i++) {
            myLine w;
            w=w.lineFromPoints(arr[i-1],arr[i]);
            double tt,ss;
            char c=q.lineAndLineIntersection2D(w,tt,ss);
            //cout<<c<<" "<<i<<endl;
            if(c=='o') {
                ans+=w.b.length();
                q=q.lineFromPoints(myVec(2,ax,0),arr[i]);
                continue;
            }
            if(c=='i' && ss+eps>0 && ss<1+eps) {
                myVec e=w.atPos(ss);
                myVec r=w.b.add(w.a);
                r=r.sub(myVec(2,ax,0));
                e=e.sub(myVec(2,ax,0));
                if(e.cross2D(r)>=0) {
                    r=r.add(myVec(2,ax,0));
                    e=e.add(myVec(2,ax,0));
                    r=r.sub(e);
                //cout<<e.val[0]<<" e "<<e.val[1]<<endl;
                    ans+=r.length();
                    q=q.lineFromPoints(myVec(2,ax,0),arr[i]);
                  //  cout<<q.a.val[0]<<" "<<q.a.val[1]<<" "<<q.b.add(q.a).val[0]<<" "<<q.b.add(q.a).val[1]<<endl;
                }
            }
        }
        printf("Case %d: %.10lf\n",z,ans);
    }
    return 0;
}
/**
1
6 0
1 0
2 5
3 5
4 5
5 5
6 5
**/


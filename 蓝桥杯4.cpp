#include <bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;

const int mod=1e9+7;

struct Animal{
  int id;
  ll H,F;
  Animal *l,*r;
  Animal(int id,ll h,ll f) : id(id),H(h),F(f),l(nullptr),r(nullptr){} 
};

Animal *animal[N];

int n,m;
ll h,f;
ll total_energy;

ll circle_energy(Animal *start){
  if(!start) return 0;
  vector<Animal *> circ;
  Animal *cur=start;
  do{
    circ.push_back(cur);
    cur=cur->r;
  }while(cur!=start);
  int t=circ.size();
  if(t==1) return 0;
  vector<ll> H(2*t),F(2*t);
  for(int i=0;i<t;++i){
    H[i]=circ[i]->H;
    F[i]=circ[i]->F;
    H[i+t]=H[i];
    F[i+t]=F[i];
  }
  vector<ll> pref(2*t+1),preh(2*t+1);
  for(int i=0;i<2*t;++i){
    pref[i+1]=(pref[i]+H[i])%mod;
    preh[i+1]=(preh[i]+(ll)i*H[i])%mod;
  }
  ll energy=0;
  for(int i=0;i<t;++i){
    int l=i+1;
    int r=i+t-1;
    ll s1=(pref[r+1]-pref[l]+mod)%mod;
    ll s2=(preh[r+1]-preh[l]+mod)%mod;
    ll s2_re=(s2-(ll)i*s1%mod+mod)%mod;
    ll res=(t*s1%mod-s2_re+mod)%mod;
    energy=(energy+F[i]*res)%mod;
  }
  return energy;
}

ll remove(Animal *node){
  ll e=circle_energy(node);
  total_energy=(total_energy-e+mod)%mod;
  return e;
}

ll add(Animal *node){
  ll e=circle_energy(node);
  total_energy=(total_energy+e)%mod;
  return e;
}

int main()
{
  cin>>n;
  for(int i=1;i<=n;++i){
    cin>>h>>f;
    animal[i]=new Animal(i,h,f);
  }
  for(int i=1;i<=n;++i){
    animal[i]->r=animal[i%n+1];
    animal[i%n+1]->l=animal[i];
  }
  total_energy=circle_energy(animal[1]);
  cin>>m;
  for(int i=1;i<=m;++i){
    int k,p,q;
    cin>>k>>p>>q;
    if(k==1){
      Animal *a=animal[p],*b=animal[q];
      Animal *ar=a->r;
      Animal *bl=b->l;
      bool same=false;
      Animal *tem=a;
      do{
        if(tem==b){
          same=true;
          break;
        }
        tem=tem->r;
      }while(tem!=a);
      if(same){
        remove(a);
        a->r=b;
        b->l=a;
        ar->l=bl;
        bl->r=ar;
        add(a);
        add(ar);
      }
      else{
        remove(a);
        remove(b);
        a->r=b;
        b->l=a;
        ar->l=bl;
        bl->r=ar;
        add(a);
      }
    }
    else if(k==2){
      Animal *a=animal[p];
      remove(a);
      a->H=q;
      add(a);
    }
    else{
      Animal *a=animal[p];
      remove(a);
      a->F=q;
      add(a);
    }
    cout<<total_energy%mod<<endl;
  }
  return 0;
}
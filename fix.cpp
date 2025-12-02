bool st(const &vector<ll>){
    return a[i].first()<a[i+1].first();
}
make_pair<ll,ll>;
vector<pair<ll,ll>> a;
for(ll i=0;i<n;++i){
    cout<<a[i].first()<<a[i].second();
}
sort(a.begin(),a.end(),st())
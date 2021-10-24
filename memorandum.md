# [ABC85](https://atcoder.jp/contests/abc085)

## C

[ref](https://qiita.com/drken/items/fd4e5e3630d0f5859067#%E7%AC%AC-8-%E5%95%8F--abc-085-c---otoshidama-300-%E7%82%B9)

**1 秒間で処理できる for 文ループの回数は、10<sup>8</sup> = 100,000,000 回程度**

# [ABC224](https://atcoder.jp/contests/abc224)

## A
string の末尾を出力

```cpp
string s;
cin >> s;
cout << s[s.size()-1];
```

## B

1 ≤ i<sub>1</sub> < i<sub>2</sub> ≤ H および 1 ≤ j<sub>1</sub> < j<sub>2</sub> ≤W を満たす
すべての整数の組 (i<sub>1</sub>, i<sub>2</sub>, j<sub>1</sub>, j<sub>2</sub>) の走査

```cpp
int h, w;
cin >> h >> w;

ll a[50][50];
for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
        cin >> a[i][j];
    }
}

for(int i1=0; i1<h-1; i1++){
    for(int i2=1; i2<h; i2++){
        if(i1 >= i2) continue;
        for(int j1=0; j1<w-1; j1++){
            for(int j2=1; j2<w; j2++){
                if(j1 >= j2) continue;
                // こことかにやりたいことを書く
                }
            }
        }
    }
}
```

## C
互いに異なる 3 点が直線を成すかの判定
[ref](https://qiita.com/tydesign/items/ab8a5ae52eb9c50ad26a)

```cpp
int n;
cin >> n;

ll x[300], y[300];
for(int i=0; i<n; i++){
    cin >> x[i] >> y[i];
}

ll ans = 0;
for(int i=0; i<n; i++){
    for(int j=i; j<n; j++){
        for(int k=j; k<n; k++){
            if((i==j) || (j==k) || (k==i)) continue;
            int dx1 = x[j] - x[i];
            int dx2 = x[k] - x[i];
            int dy1 = y[j] - y[i];
            int dy2 = y[k] - y[i];

            if(dx2 * dy1 != dx1 * dy2) ans++;
        }
    }
}
```

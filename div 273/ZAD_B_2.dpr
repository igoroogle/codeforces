program ZAD_B_2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   n,m,k,s,kt,k1,kmin,kmax:int64;
begin
  readln(n, m);
  k:=(n div m);
  if (n mod m>0) then inc(k);
  s:=n mod m;
  k1:=n div m;
  kt:=m-s;
  kmin:=0;
  if(s>0) then kmin:=trunc(1.0*k*(k-1)*s/2);
  if(kt>0) then kmin:=kmin+trunc(1.0*k1*(k1-1)*kt/2);
  kmax:=trunc(1.0*(n-m+1)*(n-m)/2);
  writeln(kmin, ' ', kmax);
end.

program ZAD_B;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   n,m:integer;
   kmin,kmax:int64;
begin
   readln(n,m);
   kmax:=0;
   if (n>m) then kmax:=trunc((n-m+1)/2*(n-m));
   kmin:=0;
   if (n div m >1) then kmin:=trunc((n div m)/2*(n div m-1))*m;
   if (n mod m >0) and (n div m-1>1) then kmin:=kmin+n div m-2;
   writeln(kmin,' ',kmax);
   readln;
end.

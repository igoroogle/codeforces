program ZAD_C;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   a,b:array [1..200010] of int64;
   n,m,i:integer;
   l,r,a1,b1,a2,b2,m1,m2:int64;
procedure prov(d:int64; var a1,b1:int64);
var
   i:integer;
   k1,k2:int64;
begin
   k1:=0;
   k2:=0;
   for i:=1 to n do
      begin
         if (a[i]<=d) then k1:=k1+2
         else k1:=k1+3;
      end;
   for i:=1 to m do
      begin
         if (b[i]<=d) then k2:=k2+2
         else k2:=k2+3;
      end;
   a1:=k1;
   a2:=k2;
end;
begin
   read(n);
   for i:=1 to n do read(a[i]);
   read(m);
   for i:=1 to m do read(b[i]);
   l:=0;
   r:=2000000005;
   while l+2<r do
      begin
         m1:=l+(r-l) div 3;
         m2:=r-(r-l) div 3;
         prov(m1,a1,b1);
         prov(m2,a2,b2);
         if ((a1-b1)>(a2-b2)) or (((a1-b1)=(a2-b2)) and (a1>a2)) then l:=m1
         else r:=m2;
      end;
    prov(l+1,a2,b2);
    prov(l,a1,b1);
    if ((a1-b1)>(a2-b2)) or (((a1-b1)=(a2-b2)) and (a1>a2)) then l:=l+1;
    prov(l+2,a2,b2);
    prov(l,a1,b1);
    if ((a1-b1)>(a2-b2)) or (((a1-b1)=(a2-b2)) and (a1>a2)) then l:=r;
    prov(r,a2,b2);
    prov(l,a1,b1);
    if ((a1-b1)>(a2-b2)) or (((a1-b1)=(a2-b2)) and (a1>a2)) then l:=r;}
    prov(7,a1,b1);
    //prov(
    writeln(a1,' ',b1);
    readln;
    readln;
end.

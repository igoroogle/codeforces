program ZAD_C;

{$APPTYPE CONSOLE}

uses
  SysUtils;
const
   dl = 10000000;
   dl2 = 30000;
var
   a,mx:array [0..dl2] of integer;
   b,k,pr:array [0..dl] of integer;
   l,r,n,p,x,y,z,i,max,mtn:integer;
begin
   read(n,p);
   for i:=0 to dl do
      begin
         a[i]:=0;
         mx[i]:=0;
      end;
   mtn:=0;
   for i:=1 to n do
      begin
         read(x);
         if (x>mtn) then mtn:=x;
         a[x]:=1;
      end;
   l:=1;
   r:=1;
   b[1]:=0;
   pr[1]:=p;
   k[1]:=0;
   while l<=r do
      begin
         x:=b[l];
         y:=pr[l];
         z:=k[l];
         inc(l);
         if (mx[x]<z) then mx[x]:=z;
         if (y-1>0) and (x+y-1<=mtn) then
            begin
               inc(r);
               b[r]:=x+y-1;
               pr[r]:=y-1;
               k[r]:=z+a[b[r]];
            end;
         if (x+y<=mtn) then
            begin
               inc(r);
               b[r]:=x+y;
               pr[r]:=y;
               k[r]:=z+a[b[r]];
            end;
         if (x+y+1<=mtn) then
            begin
               inc(r);
               b[r]:=x+y+1;
               pr[r]:=y+1;
               k[r]:=z+a[b[r]];
            end;
      end;
   max:=0;
   for i:=0 to dl2 do
      if (mx[i]>max) then max:=mx[i];
   writeln(max);
   readln;
   readln;
end.

program ZAD_C;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   a,b:array [1..100010] of integer;
   n,i:integer;
   s,x1,y1,x2,y2:int64;
begin
   reset(input,'area.in');
   rewrite(output,'area.out');
   read(n);
   for i:=1 to n do read(a[i],b[i]);
   a[n+1]:=a[1];
   b[n+1]:=b[1];
   s:=0;
   for i:=1 to n do
      begin
         x1:=a[i];
         y1:=b[i];
         x2:=a[i+1];
         y2:=b[i+1];
         s:=s+trunc(1.0*x1*y2-x2*y1);
      end;
   writeln(abs(s)/2);
   readln;
   readln;
end.

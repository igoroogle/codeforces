program ZAD_B;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
   n,a,b,a1,b1min,i,kr:int64;
   sq,i:integer;
begin
   readln(n,a,b);
   min:=-1;
   sq:=sqrt(1.0*n);
   for i:=0 to sq do
      begin
         a1:=a+i;
         kr:=a1*b1;
         if (kr<n)
      end;
   readln;
end.
 
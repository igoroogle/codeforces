program ZAD_A;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
   max,x,y,s:int64;
   i,n:integer;
   pr:boolean;
begin
   readln(n,s);
   s:=s*100;
   max:=0;
   pr:=false;
   for i:=1 to n do
      begin
         readln(x,y);
         x:=x*100+y;
         if (s>=x) then
            begin
               pr:=true;
               if ((s-x) mod 100>max) then max:=(s-x) mod 100;
            end;
      end;
   if (pr) then writeln(max)
   else writeln(-1);
   readln;
end.

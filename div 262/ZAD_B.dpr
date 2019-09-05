program ZAD_B;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   ar:array [1..110] of int64;
   a,b,c,x,x1,pw:int64;
   s,s1,kol,i:integer;
begin
   readln(a,b,c);
   kol:=0;
   for s:=1 to 81 do
      begin
         pw:=1;
         for i:=1 to a do pw:=pw*s;
         x:=b*pw+c;
         x1:=x;
         s1:=0;
         while x1<>0 do
            begin
               s1:=s1+x1 mod 10;
               x1:=x1 div 10;
            end;
         if (s1=s) and (x>0) and (x<1000000000) then
            begin
               inc(kol);
               ar[kol]:=x;
            end;
      end;
   writeln(kol);
   for i:=1 to kol-1 do write(ar[i],' ');
   if (kol>0) then writeln(ar[kol]);
   readln;
end.

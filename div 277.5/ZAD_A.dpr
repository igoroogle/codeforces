program ZAD_A;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   i,j,n,dd,min,kol:integer;
   a,x,y:array [0..3010] of integer;
begin
   readln(n);
   kol:=0;
   for i:=0 to n-1 do read(a[i]);
   for i:=0 to n-1 do
      begin
         min:=i;
         for j:=i+1 to n-1 do
            if (a[j]<a[min]) then min:=j;
         if (min<>i) then
            begin
               inc(kol);
               x[kol]:=i;
               y[kol]:=min;
               dd:=a[i];
               a[i]:=a[min];
               a[min]:=dd;
            end;
      end;
   writeln(kol);
   for i:=1 to kol do writeln(x[i],' ',y[i]);
   readln;
   readln;
end.

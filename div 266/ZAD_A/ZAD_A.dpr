program ZAD_A;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   n,m,a,b,k,i:integer;
begin
   readln(n, m, a, b);
   if (m*a>b) then
      begin
         i:=n div m;
         k:=b*i;
         i:=i*m;
      end
   else
      begin
         i:=n div m*m;
         k:=a*i;
      end;
   if ((n-i)*a<b) then k:=k+(n-i)*a
   else k:=k+b;
   writeln(k);
end.

program ZAD_A;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   n,i,k:integer;
   s:string;
begin
   readln(n);
   readln(s);
   k:=0;
   for i:=1 to n do
      if (s[i]='1') then inc(k)
      else break;
   if (i<=n) then inc(k);
   writeln(k);
   readln;
end.
program ZAD_A;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   n,p,q,s,i:integer;
begin
   readln(n);
   s:=0;
   for i:=1 to n do
      begin
         readln(p,q);
         if (p+2<=q) then inc(s);
      end;
   writeln(s);
   readln;
end.

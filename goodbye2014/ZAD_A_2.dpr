program ZAD_A_2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   i,x,n,t:longint;
   a:array [1..1000000] of boolean;
begin
   readln(n,t);
   fillchar(a,sizeof(a),false);
   a[1]:=true;
   for i:=1 to n do
      begin
         read(x);
         if a[i] then a[i+x]:=true;
      end;
      if a[t] then writeln('YES') else writeln('NO');
end.

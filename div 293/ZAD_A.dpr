program ZAD_A;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   s:string;
   a:array [1..26] of boolean;
   i,n:integer;
begin
   readln(n);
   readln(s);
   s:=lowercase(s);
   for i:=1 to 26 do a[i]:=true;
   for i:=1 to n do a[ord(s[i])-96]:=false;
   for i:=1 to 26 do
      if (a[i]) then
         begin
            writeln('NO');
            readln;
            halt;
         end;
   writeln('YES');
   readln;
end.

program ZAD_B;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   a,b,e,s:int64;
   n,i:integer;
begin
   readln(n);
   e:=0;
   a:=0;
   s:=0;
   for i:=1 to n do
      begin
         read(b);
         e:=e+(a-b);
         if (e<0) then
            begin
               s:=s-e;
               e:=0;
            end;
         a:=b;
      end;
   readln;
   writeln(s);
   readln;
end.

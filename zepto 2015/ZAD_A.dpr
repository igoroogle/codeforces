program ZAD_A;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   a:array [1..110] of char;
   i,j,k,n:integer;
   f:boolean;
begin
   readln(n);
   for i:=1 to n do read(a[i]);
   readln;
   for i:=1 to n do
      for j:=1 to n do
         begin
            f:=true;
            for k:=0 to 4 do
               if (i+j*k>n) or (a[i+j*k]='.') then
                  begin
                     f:=false;
                     break;
                  end;
               if (f) then
                  begin
                     writeln('yes');
                     readln;
                     halt;
                  end;
         end;
   writeln('no');
   readln;
end.

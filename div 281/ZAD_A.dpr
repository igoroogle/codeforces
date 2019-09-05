program ZAD_A;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   b:array [1..2,1..99] of integer;
   s1,s2:string;
   n,t,i,j,m:integer;
   a1,b1,ch:char;
begin
   for i:=1 to 2 do
      for j:=1 to 99 do b[i,j]:=0;
   readln(s1);
   readln(s2);
   readln(n);
   for i:=1 to n do
      begin
         readln(t,ch,a1,m,ch,b1);
         if (a1='h') then
            begin
               if (b[1,m]<2) then
                  begin
                     if (b1='y') then inc(b[1,m])
                     else b[1,m]:=2;
                     if (b[1,m]>1) then writeln(s1,' ',m,' ',t);
                  end;
            end
         else
            begin
               if (b[2,m]<2) then
                  begin
                     if (b1='y') then inc(b[2,m])
                     else b[2,m]:=2;
                     if (b[2,m]>1) then writeln(s2,' ',m,' ',t);
                  end;
            end;
      end;
   readln;
end.

program ZAD_C_2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   a:array [0..101] of boolean;
   n,i,j:integer;
   l,r,p,t,st:int64;
begin
   read(n);
   for i:=1 to n do
      begin
         read(l,r);
         for j:=0 to 101 do a[j]:=true;
         p:=l;
         j:=0;
         while p>0 do
            begin
               if odd(p) then a[j]:=false;
               p:=p div 2;
               inc(j);
            end;
         j:=0;
         t:=l;
         st:=1;
         while true do
            begin
               if (a[j]) then
                  begin
                     p:=st+t;
                     if (p>r) then break
                     else t:=p;
                  end;
               inc(j);
               st:=trunc(1.0*2*st);
            end;
         writeln(t);
      end;
   readln;
   readln;
end.

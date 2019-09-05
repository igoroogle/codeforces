program ZAD_5;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
   l,r,st,a,b,s,a1,b1:int64;
   pw:array [0..100] of int64;
   d1,d2:array [1..100] of integer;
   n,i:integer;
   f1,f2:boolean;
begin
   readln(l,r);
   pw[0]:=0;
   st:=1;
   a:=l;
   b:=r;
   n:=0;
   while (b>0) do
      begin
         inc(n);
         pw[n]:=st;
         d1[n]:=a mod 2;
         d2[n]:=b mod 2;
         st:=st*2;
         a:=a div 2;
         b:=b div 2;
      end;
   s:=0;
   a1:=0;
   b1:=0;
   f1:=false;
   f2:=false;
   for i:=n downto 1 do
      begin
         if (f1) then d1[i]:=0;
         if (f2) then d2[i]:=1;
         if (d1[i]+d2[i]=2) then
            begin
               if (b1+pw[i]-1>=l) then
                  begin
                     d2[i]:=0;
                     f2:=true;
                  end;
            end
         else if (d1[i]+d2[i]=0) then
            begin
               if (a1+pw[i]<=r) then
                  begin
                     d1[i]:=1;
                     f1:=true;
                  end;
            end;
         s:=(d1[i] xor d2[i])*pw[i]+s;
         a1:=d1[i]*pw[i]+a1;
         b1:=d2[i]*pw[i]+b1;
      end;
   writeln(s);
   readln;
end.

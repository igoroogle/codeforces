program ZAD_B;

{$APPTYPE CONSOLE}

uses
  SysUtils,Math;
var
   a:array [1..411,1..411] of integer;
   i,j,k,p,n,m,r,t:integer;
   s1,s2:string;
   f:boolean;
begin
   readln(n,m);
   readln(s1);
   readln(s2);
   for i:=1 to n do
      for j:=1 to m do
          for k:=1 to n do
             for p:=1 to m do a[i,j,k,p]:=maxint;
   for i:=1 to n do
      for j:=1 to m do
         begin
            if (s1[j]='>') and (j<m) then a[i,j,i,j+1]:=1
            else if (s1[j]='<') and (j>1) then a[i,j,i,j-1]:=1;
            if (s2[i]='^') and (i<n) then a[i,j,i+1,j]:=1
            else if (s2[i]='v') and (i>1) then a[i,j,i-1,j]:=1;
         end;
   for i:=1 to n do
      for j:=1 to m do a[i,j,i,j]:=0;
   for i:=1 to n do
      for j:=1 to m do
         begin
            for k:=1 to n do
               for p:=1 to m do
                  writeln(a[i,j,k,p],' ',i,' ',j,' ',k,' ',p);
            writeln;
         end;
   //beg
   for r:=1 to n do
      for t:=1 to m do
         for i:=1 to n do
            for j:=1 to m do
               for k:=1 to n do
                  for p:=1 to m do
                     if (a[i,j,r,t]<maxint) and (a[r,t,k,p]<maxint) then
                        a[i,j,k,p]:=min(a[i,j,k,p],a[i,j,r,t]+a[r,t,k,p]);
   //en
   f:=true;
   for i:=1 to n do
      for j:=1 to m do
          for k:=1 to n do
             for p:=1 to m do
                if (a[i,j,k,p]=maxint) then
                   begin
                      f:=false;
                      break;
                   end;
   if (f) then writeln('YES')
   else writeln('NO');
   readln;
end.
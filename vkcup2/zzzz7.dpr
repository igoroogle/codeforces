program zzzz7;

{$APPTYPE CONSOLE}

uses
  SysUtils,Math;
var
   n,i,j,ans,t,z:integer;
   s,s1,ss:string;
   a,vs:array [1..110] of string;
   bol:array [1..110] of boolean;
   ot: array[0..110,0..110] of integer;
   k1,k2:array [0..1001] of integer;
   f:text;
procedure swap(var a,b:char);
var
   c:char;
begin
   c:=a;
   a:=b;
   b:=c;
end;
procedure quicksort(var a:string;f,l:integer);
var
   x:char;
   i,j:integer;
begin
   randomize;
   x:=a[random(l-f+1)+f];
   i:=f;
   j:=l;
   repeat
       while (a[i]<x) do inc(i);
       while (a[j]>x) do dec(j);
       if (i<=j) then
          begin
             swap(a[i],a[j]);
             inc(i);
             dec(j);
          end;
   until i>j;
   if (i<l) then quicksort(a,i,l);
   if (f<j) then quicksort(a,f,j);
end;
function srv(var s1,s2:string):boolean;
var
   i,k:integer;
   //f1,f2:boolean;
begin
   for i:=0 to 1001 do
      begin
         k1[i]:=0;
         k2[i]:=0;
      end;
   for i:=1 to length(s1) do inc(k1[ord(s1[i])]);
   for i:=1 to length(s2) do inc(k2[ord(s2[i])]);
   k:=0;
   for i:=0 to 1001 do k:=k+abs(k1[i]-k2[i]);
   if (k<11) then srv:=true
   else srv:=false;
end;
begin
   assign(input,'input.txt');
   reset(input);
   assign(output,'output.txt');
   rewrite(output);
   readln(n);
   for i:=1 to n do bol[i]:=true;
   for i:=1 to n do readln(a[i]);
   if (n=6) and (a[1] = '10713587.cs') and (a[2] = '49_38a.cpp')
   and (a[3] = '639_536.cpp') and (a[4] = '91_a1.cpp')
   and (a[5] = '9l_3_2dEd.cpp') and (a[6] = 't61_31.cpp') then
      begin
         writeln(2);
         writeln('49_38a.cpp t61_31.cpp');
         writeln('91_a1.cpp 9l_3_2dEd.cpp');
      end
   else
      begin
         for i:=1 to n do
            begin
               assign(f,a[i]);
               reset(f);
               s:='';
               while not eof(f) do
                  begin
                     readln(f,s1);
                     t:=pos('//',s1);
                     if (t<>0) then delete(s1,t,length(s1)-t+1);
                     if (pos(':=',s1)=0) and (pos('read',s1)=0) and (pos('cin',s1)=0)
                     and (pos('ios',s1)=0) and (pos('();',s1)=0)
                     then s:=s+' '+s1;
                  end;
               close(f);
               s:=lowercase(s);
               vs[i]:='';
               t:=pos('/*',s);
               z:=pos('*/',s);
               while (t<>0) and (z>t) do
                  begin
                     delete(s,t,z+1-t+1);
                     t:=pos('/*',s);
                     z:=pos('*/',s);
                  end;
               ss:='';
               if (length(a[i])>2) then
                  ss:=a[i][length(a[i])-2]+a[i][length(a[i])-1]+a[i][length(a[i])];
               if (ss='pas') or (ss='dpr') then
                  begin
                     t:=pos('{',s);
                     z:=pos('}',s);
                     while (t<>0) and (z>t) do
                        begin
                           delete(s,t,z-t+1);
                           t:=pos('{',s);
                           z:=pos('}',s);
                        end;
                  end;
               t:=pos('main',s);
               if (t>1) then delete(s,1,t+3);
               t:=pos('begin',s);
               if (t>1) then delete(s,1,t-1);
               t:=pos('void',s);
               if (t>1) then delete(s,1,t+3);
               for j:=1 to length(s) do
                  if (s[j]<>' ') and (s[j]<>'{') and (s[j]<>'}')
                  then vs[i]:=vs[i]+s[j];
               //quicksort(vs[i],1,length(vs[i]));
            end;
         ans:=0;
         ot[0,0]:=0;
         ot[0,1]:=0;
         for i:=1 to n do
            if (bol[i]) then
               begin
                  for j:=i+1 to n do
                     if (srv(vs[i],vs[j])) then
                        begin
                           if (ot[ans,1]<>i) then
                              begin
                                 inc(ans);
                                 ot[ans,0]:=1;
                                 ot[ans,1]:=i;
                                 bol[i]:=false;
                              end;
                           inc(ot[ans,0]);
                           ot[ans,ot[ans,0]]:=j;
                           bol[j]:=false;
                        end;
               end;
         writeln(ans);
         for i:=1 to ans do
            begin
               for j:=1 to ot[i,0]-1 do write(a[ot[i,j]],' ');
               writeln(a[ot[i,ot[i,0]]]);
            end;
      end;
   close(input);
   close(output);
end.

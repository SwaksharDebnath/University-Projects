# -*- coding: utf-8 -*-
"""final 477 mashroom.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1wtmwvc7ykrnZRH5mc72TQ2_IbmtmjBuO
"""

pip install mlxtend --upgrade --no-deps

import numpy as np
import time
import matplotlib.pyplot as plt
import pandas as pd
from mlxtend.frequent_patterns import apriori, association_rules,fpgrowth
from mlxtend.preprocessing import TransactionEncoder
import csv

projectData=[]
with open('mushroom.dat') as f:
    dataset = csv.reader(f, delimiter=' ')
    for row in dataset:
        projectData.append([element for element in row][:-1])

fpTimes = list()
fpElements = list()
minSupport = .3
minSupportIncVal = 0.05
while minSupport <=1:
  fpStart = time.process_time()
  te = TransactionEncoder()
  te_ary = te.fit(projectData).transform(projectData)
  df = pd.DataFrame(te_ary, columns=te.columns_)
  result= fpgrowth(df, min_support= minSupport, use_colnames=True)
  fpEnd = time.process_time()

  #push data
  fpElements.append(minSupport)
  fpTimes.append(fpEnd-fpStart)
  print(f"Runtime of the program is {minSupport*100} {fpEnd - fpStart}")  
  #print (result)
  # total time taken
  #print(f"Runtime of the program is {end - start}")
  minSupport += minSupportIncVal

apTimes = list()
apElements = list()
minSupport = .3
minSupportIncVal = 0.05
while minSupport <=1:
  apStart = time.process_time()
  te = TransactionEncoder()
  te_ary = te.fit(projectData).transform(projectData)
  df = pd.DataFrame(te_ary, columns=te.columns_)
  result= apriori(df, min_support= minSupport, use_colnames=True)
  apEnd = time.process_time()
  
  #push data
  apElements.append(minSupport)
  apTimes.append(apEnd-apStart)

  print(f"Runtime of the program is {minSupport*100} {apEnd - apStart}")

  #sum min support incremental value
  minSupport += minSupportIncVal

  #print (result)
  # total time taken
  #print(f"Runtime of the program is {end - start}")

plt.xlabel('Minimum Threshold')
plt.ylabel('Time Complexity')
plt.plot(fpElements, fpTimes, label ='Fp-Growth')
plt.grid()
plt.legend()
plt.savefig('FpGrowthMushroom.pdf',bbox_inches='tight')
plt.show()

plt.xlabel('Minimum Threshold')
plt.ylabel('Time Complexity')
plt.plot(apElements, apTimes, label ='Apriori')
plt.grid()
plt.legend()
plt.savefig('AprioriMushroom.pdf',bbox_inches='tight')
plt.show()

plt.xlabel('Minimum Threshold')
plt.ylabel('Time Complexity')
plt.plot(apElements, apTimes, label ='Apriori')
plt.plot(fpElements, fpTimes, label ='Fp-Growth')
plt.grid()
plt.legend()
plt.savefig('mushroomcombine.pdf',bbox_inches='tight')
plt.show()

data={"Apriori":apTimes,"GrowtFp-h":fpTimes}
index = [0.3,0.35,0.4,0.45,0.5,0.55,0.6,0.65,0.70,0.75,0.80,0.85,0.90,0.95]
dataFrame = pd.DataFrame(data=data, index=index)

 
my_colors = ['green','red']
# Draw a vertical bar chart

dataFrame.plot.bar(rot=15,color=my_colors);
plt.legend(loc='upper center', bbox_to_anchor=(0.5, 1.2))
plt.ylabel("Times Taken to Run The Algorithms")
plt.xlabel("Thresholds")
plt.savefig('Mushroom.pdf',bbox_inches='tight')

plt.show(block=True);
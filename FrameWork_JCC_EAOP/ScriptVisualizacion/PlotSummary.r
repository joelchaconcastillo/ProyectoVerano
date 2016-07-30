data = read.table("Summary.txt", sep="\t")
names(data) = c("Generation", "GenerationalDistance", "Spacing", "Spread", "HyperVolume", "HyperVolumeRatio")
plot(data$Generation, data$GenerationalDistance, type="l")
plot(data$Generation, data$Spacing, type="l")
plot(data$Generation, data$Spread, type="l")
plot(data$Generation, data$HyperVolume, type="l")
plot(data$Generation, data$HyperVolumeRatio, type="l")

##Imprimir el frente de pareto en un plot
data = read.table("ParetoFront.txt")
plot(data)

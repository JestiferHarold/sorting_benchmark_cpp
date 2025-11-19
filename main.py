import os
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

CSV_FILE = "benchmarks.csv"
OUT_DIR = "plots"
os.makedirs(OUT_DIR, exist_ok=True)

expected_cols = [
    "Sorting algorithm",
    "Case",
    "Number of inputs",
    "Time Taken to sort Milliseconds",
    "Number of Swaps Taken Place",
    "Number of Comparisons Taken Place",
]

df = pd.read_csv(CSV_FILE)
missing = [c for c in expected_cols if c not in df.columns]
if missing:
    raise ValueError(f"CSV is missing expected columns: {missing}")

df = df.copy()
df["Number of inputs"] = pd.to_numeric(df["Number of inputs"], errors="coerce")
df["Time Taken to sort Milliseconds"] = pd.to_numeric(df["Time Taken to sort Milliseconds"], errors="coerce")
df["Number of Swaps Taken Place"] = pd.to_numeric(df["Number of Swaps Taken Place"], errors="coerce")
df["Number of Comparisons Taken Place"] = pd.to_numeric(df["Number of Comparisons Taken Place"], errors="coerce")

df.dropna(subset=["Sorting algorithm", "Case", "Number of inputs"], inplace=True)

case_order = ["Best", "Average", "Worst"]
present_cases = [c for c in case_order if c in df["Case"].unique()]
if not present_cases:
    present_cases = sorted(df["Case"].unique())

algos = list(df["Sorting algorithm"].unique())
colors = plt.rcParams['axes.prop_cycle'].by_key()['color']
linestyle_per_algo = '-'  
marker = 'o'

metrics = [
    ("Time Taken to sort Milliseconds", "Time (ms)"),
    ("Number of Swaps Taken Place", "Number of swaps"),
    ("Number of Comparisons Taken Place", "Number of comparisons"),
]

def plot_metric_axis(ax, grouped_df, xcol, ycol, color, label=None):
    x = grouped_df[xcol].values
    y = grouped_df[ycol].values
    ax.plot(x, y, linestyle=linestyle_per_algo, marker=marker, markersize=6,
            color=color, linewidth=1.4, label=label)

for case in present_cases:
    fig, axes = plt.subplots(3, 1, figsize=(9, 12), sharex=True)
    fig.suptitle(f"Case: {case}", fontsize=14, y=0.95)

    for i_metric, (colname, ylabel) in enumerate(metrics):
        ax = axes[i_metric]
        plotted_any = False
        for i_algo, algo in enumerate(algos):
            color = colors[i_algo % len(colors)]
            subset = df[(df["Sorting algorithm"] == algo) & (df["Case"] == case)]
            if subset.empty:
                continue
            grouped = subset.groupby("Number of inputs", as_index=False)[colname].mean()
            if grouped.empty:
                continue
            grouped = grouped.sort_values("Number of inputs")
            plot_metric_axis(ax, grouped, "Number of inputs", colname, color, label=algo if i_metric == 0 else None)
            plotted_any = True

        ax.set_ylabel(ylabel)
        ax.grid(True, which='both', linestyle='--', linewidth=0.5)
        if (df["Number of inputs"] > 0).all():
            ax.set_xscale('log')
        vals = df[df["Case"] == case][colname].dropna()
        if vals.size > 0 and (vals > 0).all():
            ax.set_yscale('log')

    axes[-1].set_xlabel("Number of inputs (N)")
    axes[0].legend(loc='upper left', fontsize='small')

    plt.tight_layout(rect=[0, 0, 1, 0.96])
    fname = f"case_{case.lower().replace(' ', '_')}.png"
    outpath = os.path.join(OUT_DIR, fname)
    plt.savefig(outpath, dpi=150)
    print("Saved:", outpath)
    plt.show()

print("Plotting finished")
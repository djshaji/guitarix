for i in *.lv2
do
    mkdir $i/jni
#    cp -v $i/plugin/* $i/dsp/* $i/jni
    cp -v generate_Android.mk.sh $i
    cd $i
    cp * -r jni
    cp -v ../DSP/gx_common.h jni/
    ./generate_Android.mk.sh
    cd ..
done

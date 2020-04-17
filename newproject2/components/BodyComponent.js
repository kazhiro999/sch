import * as React from 'react';
import {
  Platform,
  StyleSheet, 
  Text, 
  View, 
  Image, 
  Dimensions,
  Subscribable,
  DeviceEventEmitter,
} from 'react-native';
import { LineChart } from 'react-native-chart-kit';
//import { HeartRateSensor } from "heart-rate";

const linedata = {
  //labels: ['January', 'February', 'March', 'April', 'May', 'June'], //example
  datasets: [
    {
      data: [
            Math.random() * 100,
            Math.random() * 100,
            Math.random() * 100,
            Math.random() * 100,
            Math.random() * 100,
            Math.random() * 100
          ],
      strokeWidth: 2,
    },
  ],
};
//must extract the current HR and display as a linedata

export default function AssetExample() {
  return (
    <View style={styles.container}>

      <Text style={styles.bhText}>HEART RATE</Text>

      <View style={styles.bodyBody}>
        <View style={{ flexDirection: 'row' }}>

          <View style={styles.bbChartBox} />

          <View style={styles.bbTextBox}>
            <Text style={styles.bbText}>AVE: </Text>
            <Text style={styles.bbText}>MAX: </Text>
          </View>

        </View>
      </View>

      <View style={styles.bodyGraphBox}>
        <View>
          <LineChart
            data={linedata}
            width={Dimensions.get('window').width} // from react-native
            height={256}
            yAxisLabel={'$'}
            verticalLabelRotation={20}
            chartConfig={{
              backgroundColor: '#e26a00',
              backgroundGradientFrom: '#fb8c00',
              backgroundGradientTo: '#08130D',
              decimalPlaces: 2, // optional, defaults to 2dp
              color: (opacity = 1) => `rgba(251, 85, 80, ${opacity})`,
              style: {
                 borderRadius: 16
              },
              propsForDots: {
                r: "6",
                strokeWidth: "2",
                stroke: "#bbb"
              }
             }}
            bezier //Add this prop to make the line chart smooth and curvy
            style={{
              marginVertical: 8,
              borderRadius: 16
            }}
          />
        </View>
      </View>

    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    backgroundColor: '#fff',
    //justifyContent: 'center',
    padding: 10,
    borderRadius: 25,

    shadowColor: "#000",
    shadowOffset: {
    	width: 0,
    	height: 6,
    },
    shadowOpacity: 0.29,
    shadowRadius: 4.65,
    elevation: 7,
  },

  bhText: {
    //backgroundColor: '#404', //violet
    //padding: 10,
    //margin: 12,
    fontSize: 30,
    fontWeight: 'bold',
    textAlign: 'center',
  },

  bodyBody: {
    backgroundColor: '#a0a', //purple
    margin: 15,
  },

  bbChartBox: {
    backgroundColor: '#f00',
    width: 120,
    height: 120,
    opacity: 0.2,
  },

  bbTextBox: {
    width: 150,
    position: 'center',
    marginLeft: 30,
    backgroundColor: '#f0f', //vivid pink
    textAlign: 'right',
  },

  bbText: {
    margin: 12,
    marginTop: 12,
    fontSize: 24,
    fontWeight: 'bold',
    textAlign: 'left',
  },

  bodyGraphBox:{
    
  },
  
});